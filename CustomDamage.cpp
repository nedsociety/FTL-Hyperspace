#include "Global.h"
#include "Projectile_Extend.h"
#include "CustomWeapons.h"
#include "CrewSpawn.h"
#include <boost/lexical_cast.hpp>

CustomDamage* CustomDamageManager::currentWeaponDmg = nullptr;

HOOK_METHOD(ShipManager, DamageArea, (Pointf location, DamageParameter dmgParam, bool forceHit) -> bool)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::DamageArea -> Begin (CustomDamage.cpp)\n")
    Damage* dmg = (Damage*)&dmgParam;

    auto custom = CustomDamageManager::currentWeaponDmg;

    /*
    if (custom && custom->sourceShipId != -1)
    {
        int rng = random32() % 10;

        if (rng < custom->crewSpawnChance)
        {
            for (auto i : custom->crewSpawns)
            {
                CrewSpawn::SpawnCrew(*i, this, custom->sourceShipId != iShipId, location);
            }
        }
    }
    */

    return super(location, dmgParam, forceHit);
}

HOOK_METHOD(ShipManager, GetDodgeFactor, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> ShipManager::GetDodgeFactor -> Begin (CustomDamage.cpp)\n")
    int ret = super();

    if (CustomDamageManager::currentWeaponDmg != nullptr)
    {
        ret -= CustomDamageManager::currentWeaponDmg->accuracyMod;
    }

    return ret;
}

HOOK_METHOD_PRIORITY(ShipManager, DamageSystem, -100, (int roomId, DamageParameter dmgParam) -> void)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageSystem -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg != nullptr && CustomDamageManager::currentWeaponDmg->noSysDamage)
    {
        dmgParam.iSystemDamage -= dmgParam.iDamage;
    }

    super(roomId, dmgParam);
}

HOOK_METHOD_PRIORITY(ShipManager, DamageCrew, -100, (CrewMember *crew, DamageParameter dmgParameter) -> char)
{
    LOG_HOOK("HOOK_METHOD_PRIORITY -> ShipManager::DamageCrew -> Begin (CustomDamage.cpp)\n")
    if (CustomDamageManager::currentWeaponDmg != nullptr && CustomDamageManager::currentWeaponDmg->noPersDamage)
    {
        dmgParameter.iPersDamage -= dmgParameter.iDamage;
    }

    return super(crew, dmgParameter);
}

HOOK_METHOD(ProjectileFactory, Update, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> ProjectileFactory::Update -> Begin (CustomDamage.cpp)\n")
    // This only works if every weapon has a definition, if that changes then replace with the commented code below.
    CustomDamageManager::currentWeaponDmg = &CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)->customDamage;

    //auto def = CustomWeaponManager::instance->GetWeaponDefinition(blueprint->name)
    //if (def) CustomDamageManager::currentWeaponDmg = &def->customDamage;

    super();

    CustomDamageManager::currentWeaponDmg = nullptr;
}

HOOK_METHOD(Projectile, Initialize, (WeaponBlueprint& bp) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::Initialize -> Begin (CustomDamage.cpp)\n")
    super(bp);

    auto customDmg = CustomDamageManager::currentWeaponDmg;

    if (customDmg != nullptr)
    {
        PR_EX(this)->customDamage = *customDmg;
    }
}

HOOK_METHOD(Projectile, CollisionCheck, (Collideable *other) -> void)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::CollisionCheck -> Begin (CustomDamage.cpp)\n")
    CustomDamageManager::currentWeaponDmg = &PR_EX(this)->customDamage;
    CustomDamageManager::currentWeaponDmg->sourceShipId = ownerId;

    super(other);

    CustomDamageManager::currentWeaponDmg = nullptr;
}
