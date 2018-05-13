class Items_base_F;
class MRH_SatCom_Antenna: Items_base_F {
	author = "Mr H";
	mapSize = 0.07;
	class SimpleObject {
		eden = 1;
		animate[] = {};
		hide[] = {};
		verticalOffset = 0.131;
		verticalOffsetWorld = 0;
		init = "''";
	};
	editorPreview = "\MRHSatellite\Models\Antenna\antennapreview.jpg";
	//_generalMacro = "Land_BottlePlastic_V2_F";
	scope = 2;
	scopeCurator = 2;
	displayName = "Trivec Avant SATCOM Antenna";
	model = "\MRHSatellite\Models\Antenna\antennaMERGE.p3d";
	
	icon = "iconObject_circle";
	editorCategory = "EdCat_MRH_Sat";
	editorSubcategory = "EdSubcat_MRH_Objects";
	vehicleClass = "Small_items";
	destrType = "DestructNo";
	cost = 100;
	hiddenSelections[] = {};
	hiddenSelectionTextures[] = {};
	// ThingX
	simulation = "thingX";
	////
	ace_dragging_canDrag = 1;  // Can be dragged (0-no, 1-yes)
        ace_dragging_dragPosition[] = {0, 1.2, 0};  // Offset of the model from the body while dragging (same as attachTo)
        ace_dragging_dragDirection = 0;  // Model direction while dragging (same as setDir after attachTo)

        // Carrying
        ace_dragging_canCarry = 1;  // Can be carried (0-no, 1-yes)
        ace_dragging_carryPosition[] = {0, 1.2, 0};  // Offset of the model from the body while dragging (same as attachTo)
        ace_dragging_carryDirection = 0;  // Model direction while dragging (same as setDir after attachTo)
	/////
	
	class ACE_Actions {
		class ACE_AntennaOptions 
		{
			displayName = "Interact";
			icon = "\MRHSatellite\Paa\iconantenna.paa";
			distance = 2;
			selection = "mem01";
				class Connect {
					displayName = "Connect antenna to UTD";
					condition = "('MRH_TacticalDisplay' in items player) && ((player getVariable ['MRH_AntennaLinkedToTablet',objNull]) != _target)";
					exceptions[] = {};
					statement = "player setVariable ['MRH_AntennaLinkedToTablet',_target];_target say3d 'MRH_SAT_AntennaLinked';";
					icon = "\MRHSatellite\Paa\iconconnect.paa";
					//selection = "mem01";
					//distance = 2;
				};
				
				class Fold {
					displayName = "Fold antenna";
					condition = "true";
					exceptions[] = {};
					statement = "_storePos = getPosATL _target; deleteVehicle _target; [_storePos] call MRH_fnc_foldAntenna;";
					icon = "\MRHSatellite\Models\Antenna\antennaInvIcon.paa";
					//selection = "mem01";
					//distance = 2;
				};
		}; 
	};
	
	class UserActions
	{
		class Connect
		{
			displayName="<img image='\MRHSatellite\Paa\iconconnect.paa' size='1' shadow='false' /><t color ='#19ea2b'><t font = 'PuristaLight'>Connect antenna to UTD</t>";
			displayNameDefault = "<img image='\MRHSatellite\Paa\iconconnect.paa' size='1' shadow='false' /><t color ='#19ea2b'><t font = 'PuristaLight'>Connect antenna to UTD</t>";
            showWindow = 1;
	        hideOnUse = 0;
			priority = 0;
			shortcut = "";
			position= "mem01";
			radius= 1;
            onlyForPlayer = 1;
			condition= "('MRH_TacticalDisplay' in items player) && !('ace_common' in activatedAddons) && ((player getVariable ['MRH_AntennaLinkedToTablet',objNull]) != this)";//;'MRH_TacticalDisplay' in items player"
			statement= "player setVariable ['MRH_AntennaLinkedToTablet',this]; this say3d 'MRH_SAT_AntennaLinked';";
		};
				class Fold
		{
			displayName="<img image='\MRHSatellite\Models\Antenna\antennaInvIcon.paa' size='1' shadow='false' /><t color ='#ea2b19'><t font = 'PuristaLight'>Fold Antenna</t>";
			displayNameDefault = "<img image='\MRHSatellite\Models\Antenna\antennaInvIcon.paa' size='1' shadow='false' /><t color ='#ea2b19'><t font = 'PuristaLight'>Fold Antenna</t>";
            showWindow = 1;
	        hideOnUse = 0;
			priority = 0;
			shortcut = "";
			position= "mem01";
			radius= 1;
            onlyForPlayer = 1;
			condition= "true";
			statement= "_storePos = getPosATL this; deleteVehicle this; [_storePos] call MRH_fnc_foldAntenna;";
		};
	};	
	
	
};