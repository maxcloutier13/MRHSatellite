params ["_show"];
switch (true) do {
case _show : {
ctrlshow [1231,true];
ctrlshow [1204,true];
ctrlshow [1205,true];
ctrlshow [1206,true];
ctrlshow [1207,true];
ctrlshow [1202,true];
ctrlshow [1209,true];
ctrlshow [1215,true];
ctrlshow [1105,true];
_showFullscreen = ["MRH_SAT_allowFullscreen"] call cba_settings_fnc_get;
ctrlshow [1209, _showFullscreen];
call MRH_fnc_Compass;
};
case !_show : {
ctrlshow [1231,false];
ctrlshow [1204,false];
ctrlshow [1205,false];
ctrlshow [1206,false];
ctrlshow [1207,false];
ctrlshow [1202,false];
ctrlshow [1209,false];
ctrlshow [1215,false];
ctrlshow [1105,false];
};
};