#include "Global.h"
#include "Projectile_Extend.h"
#include "CustomWeapons.h"

CustomDamage* CustomDamageManager::currentWeaponDmg = nullptr;


HOOK_METHOD(ShipManager, DamageArea, (Pointf location, DamageParameter dmgParam, bool forceHit) -> bool)
{
    Damage* dmg = (Damage*)&dmgParam;

    auto custom = CustomDamageManager::currentWeaponDmg;

    if (custom)
    {
        if (custom->timeDilation != 0)
        {
            int roomId = ship.GetSelectedRoomId(location.x, location.y, true);

            if (roomId != -1)
            {
                RM_EX(ship.vRoomList[roomId])->timeDilation = custom->timeDilation;
            }
        }
    }

    return super(location, dmgParam, forceHit);
}

static bool g_inGetDodged = false;

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    int ret = super();

    if (g_inGetDodged && CustomDamageManager::currentWeaponDmg != nullptr)
    {
        ret -= CustomDamageManager::currentWeaponDmg->accuracyMod;
    }

    return ret;
}

HOOK_METHOD(ShipManager, GetDodged, () -> bool)
{
    return super();

    printf("no mod: %d\n", GetDodgeFactor());

    g_inGetDodged = true;
    printf("mod: %d\n", GetDodgeFactor());

    auto ret = super();
    g_inGetDodged = false;
    return ret;
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    CustomDamageManager::currentWeaponDmg = &CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->customDamage;

    super();

    CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(Projectile, Initialize, (WeaponBlueprint& bp) -> void)
{
    super(bp);

    auto customDmg = CustomDamageManager::currentWeaponDmg;

    if (customDmg != nullptr)
    {
        PR_EX(this)->customDamage = *customDmg;
    }
}

HOOK_METHOD(Projectile, CollisionCheck, (Collideable *other) -> void)
{
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
}
