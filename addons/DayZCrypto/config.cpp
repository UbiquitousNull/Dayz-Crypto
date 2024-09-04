class CfgPatches
{
    class DayzCrypto
    {
        units[] = {"ServerRack"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
    };
};

class CfgMods
{
    class DayzCrypto
    {
        dir = "DayzCrypto";
        name = "Dayz Crypto Mod";
        author = "UbiquitousNull";
        version = "1.0";
    };
};

class CfgVehicles
{
    class HouseNoDestruct;

    class ServerRack : HouseNoDestruct
    {
        scope = 2;
        displayName = "Server Rack";
        descriptionShort = "A rack to store servers and related equipment.";
        model = "\DayzCrypto\ServerRack\serverrack.p3d";
        icon = "iconObject";
        vehicleClass = "Structures";
        
        class AnimationSources
        {
            class Doors
            {
                source = "user";
                animPeriod = 1;
                initPhase = 0;
                sound = "doorMetalOpen";
            };
        };

        class UserActions
        {
            class OpenRack
            {
                displayName = "Open Server Rack";
                condition = "([this, player] call ServerRack_fnc_CanOpenDoor)";
                statement = "this animate ['Doors', 1]; hint 'Server Rack Opened';";
                onlyForPlayer = 1;
                priority = 3;
                radius = 3;
            };

            class CloseRack
            {
                displayName = "Close Server Rack";
                condition = "this animationPhase 'Doors' == 1 && player distance this < 3";
                statement = "this animate ['Doors', 0]; hint 'Server Rack Closed';";
                onlyForPlayer = 1;
                priority = 3;
                radius = 3;
            };
        };
    };
};
