#include "Global.h"

struct Skill
{
    int requirement;
    float levels[4];
};

struct SkillsDefinition
{
    SkillsDefinition()
    {


        skills["piloting"] = Skill();

        skills["piloting"].requirement = 15;
        skills["piloting"].levels[0] = 0.f;
        skills["piloting"].levels[1] = 5.f;
        skills["piloting"].levels[2] = 7.f;
        skills["piloting"].levels[3] = 10.f;

        skills["engines"] = Skill();

        skills["engines"].requirement = 15;
        skills["engines"].levels[0] = 0.f;
        skills["engines"].levels[1] = 5.f;
        skills["engines"].levels[2] = 7.f;
        skills["engines"].levels[3] = 10.f;

        skills["shields"] = Skill();

        skills["shields"].requirement = 55;
        skills["shields"].levels[0] = 1.f;
        skills["shields"].levels[1] = 1.1f;
        skills["shields"].levels[2] = 1.25f;
        skills["shields"].levels[3] = 1.3f;

        skills["weapons"] = Skill();

        skills["weapons"].requirement = 65;
        skills["weapons"].levels[0] = 0.f;
        skills["weapons"].levels[1] = 0.9f;
        skills["weapons"].levels[2] = 0.85f;
        skills["weapons"].levels[3] = 0.8f;

        skills["repair"] = Skill();

        skills["repair"].requirement = 18;
        skills["repair"].levels[0] = 1.0f;
        skills["repair"].levels[1] = 1.0f;
        skills["repair"].levels[2] = 1.1f;
        skills["repair"].levels[3] = 1.2f;

        skills["combat"] = Skill();

        skills["combat"].requirement = 8;
        skills["combat"].levels[0] = 1.0f;
        skills["combat"].levels[1] = 1.0f;
        skills["combat"].levels[2] = 1.1f;
        skills["combat"].levels[3] = 1.2f;

    }

    std::map<std::string, Skill> skills = std::map<std::string, Skill>();
};

struct TemporaryPowerDefinition
{
    float duration;

    std::string effectAnim;
    std::vector<std::string> sounds;

    float speedBoost = -1.f;
    float combatBoost = -1.f;
    float repairBoost = -1.f;
    int bonusPower;
    bool invulnerable;

    GL_Color cooldownColor;
};

struct ActivatedPowerRequirements
{
    bool playerShip;
    bool enemyShip;
    bool enemyInRoom;
    bool friendlyInRoom;
    bool systemInRoom;
};

struct ActivatedPowerDefinition
{
    Damage damage;
    float cooldown = 50.f;
    float shipFriendlyFire = false;
    bool hasSpecialPower = false;
    bool hasTemporaryPower = false;


    std::vector<std::string> sounds;


    TextString buttonLabel;
    GL_Color cooldownColor;

    TextString tooltip;
    std::string effectAnim;

    ActivatedPowerRequirements req;

    bool win = false;
    float crewHealth = 0.f;
    float enemyHealth = 0.f;
    float selfHealth = 0.f;


    TemporaryPowerDefinition tempPower;
};

struct CrewDefinition
{
    std::string race;
    std::vector<std::string> deathSounds;
    std::vector<std::string> shootingSounds;

    bool canFight = true;
    bool canSuffocate = true;
    bool canBurn = true;
    int maxHealth = 100;
    float moveSpeedMultiplier = 1.f;
    float repairSpeed = 1.f;
    float damageMultiplier = 1.f;
    bool providesPower = false;
    int bonusPower = 0;
    float fireRepairMultiplier = 1.2f;
    float suffocationModifier = 1.f;
    bool isTelepathic = false;
    bool isAnaerobic = false;
    float fireDamageMultiplier = 1.f;
    bool canPhaseThroughDoors = false;
    float oxygenChangeSpeed = 0.f;
    float damageTakenMultiplier = 1.f;
    float passiveHealAmount = 0.f;
    int passiveHealDelay = 15;
    bool detectsLifeforms = false;
    bool hasCustomDeathAnimation = false;
    bool hasDeathExplosion = false;
    std::string animBase = "human";

    Damage explosionDef;
    bool explosionShipFriendlyFire = false;

    ActivatedPowerDefinition powerDef;


    SkillsDefinition skillsDef;
};

class CustomCrewManager
{
public:
    CustomCrewManager()
    {

    }



    void AddCrewDefinition(CrewDefinition crew);
    void ParseCrewNode(rapidxml::xml_node<char> *node);
    CrewMember* CreateCrewMember(CrewBlueprint* bp, int shipId, bool intruder);
    bool IsRace(const std::string& race);
    void SetupVTable(CrewMember *crew);
    void SwapVTable(void** vtable, int index, void* swapTo);

    CrewDefinition& GetDefinition(const std::string& name)
    {
        return this->blueprintNames[name];
    }

    static CustomCrewManager *GetInstance()
    {
        return &instance;
    }

private:
    static CustomCrewManager instance;

    std::map<std::string, CrewDefinition> blueprintNames;
};
