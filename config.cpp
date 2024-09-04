class CfgPatches
{
    class DayzCrypto
    {
        units[] = {"ServerCabinet_Kit", "ServerCabinet"};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Scripts", "DZ_Structures_Furniture"};
    };
};

class CfgMods
{
    class DayzCrypto
    {
        dir="DayzCrypto";
        picture="";
        action="";
        hideName=0;
        hidePicture=1;
        name="DayzCrypto";
        credits="UbiquitousNull";
        author="UbiquitousNull";
        authorID="76561198131823069";
        version="0.1";
        extra=0;
        type="mod";
        dependencies[]= {"Game","World","Mission"};
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"DayzCrypto/scripts/3_Game"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"DayzCrypto/scripts/5_Mission"};
            };
            class missionUIScriptModule
            {
                value = "";
                files[] = {"DayzCrypto/scripts/5_MissionUI"};
            };
            class imageSetsScriptModule
            {
                value = "";
                files[] = {"DayzCrypto/scripts/ImageSets"};
            };
        };
    };
};

class CfgVehicles {
    class Container_Base; 
    class ServerCabinet_Kit: Container_Base {
        scope = 2;
        displayName = "Server Cabinet Kit";
        descriptionShort = "A kit to deploy a server cabinet.";
        model = "DayzCrypto/addons/models/server_cabinet_kit.p3d";
        itemSize[] = {10,10};
        weight = 5000; // Grams
        canBeDigged = 0;
        varQuantityDestroyOnMin = 1;
        itemBehaviour = 1; // Makes it behave like a deployable kit
        physLayer = "item_large"; // placement interaction layer
        rotationFlags = 64;
        hiddenSelectionsTextures[] = {"\path\to\texture.paa"};
        class Cargo {
            itemsCargoSize[] = {0,0}; // No cargo space in kit form
        };
        class UserActions {
            class PlaceObject {
                displayName = "Place Server Cabinet";
                position = "action";
                onlyInWorld = 1;
                condition = "true";
                statement = "[this] call DayZ::DeployCabinet";
            };
        };
    };

    class HouseNoDestruct;

    class ServerCabinet: HouseNoDestruct {
        scope = 2;
        displayName = "Server Cabinet";
        descriptionShort = "A server cabinet used to store equipment.";
        model = "\path\to\server_cabinet.p3d";
        itemSize[] = {10,10}; // Inventory size when picked up
        weight = 15000; // Custom weight when placed
        interactActions[] = {"OpenCabinetDoor", "CloseCabinetDoor"}; // Actions for door interaction
        cargoCapacity = 1000;
        canBeDigged = 0;
        rotationFlags = 64;
        hiddenSelectionsTextures[] = {"\path\to\texture.paa"};
        attachments[] = {"Inventory", "Tools"}; // Custom slots 
        class AnimationSources {
            class Door {
                source = "user";
                animPeriod = 1.0;
                initPhase = 0;
                sound = "doorOpenSound"; // Door sound for opening
            };
        };
        class UserActions {
            class OpenCabinetDoor {
                displayName = "Open Cabinet Door";
                position = "door_action";
                radius = 2.0;
                condition = "this animationPhase 'Door' == 0";
                statement = "this animate ['Door', 1];";
            };
            class CloseCabinetDoor {
                displayName = "Close Cabinet Door";
                position = "door_action";
                radius = 2.0;
                condition = "this animationPhase 'Door' == 1";
                statement = "this animate ['Door', 0];";
            };
            class PickupCabinet {
                displayName = "Pick Up Server Cabinet";
                position = "action";
                radius = 2.0;
                condition = "this getCargoWeight == 0"; // Only pick up if empty
                statement = "player addItemToInventory 'ServerCabinet_Kit'; deleteVehicle this;";
            };
        };
    };
};
