#pragma once

#define DEBUG false

#if DEBUG
#define Log(lambda) lambda()
#else
#define Log(null)
#endif // DEBUG

//Stage 1 settings
#define STG1_MAP_W 6
#define STG1_MAP_H 9
#define STG1_MAX_EXITS 2
#define STG1_MAX_PIPES ((S1_MAP_W * S1_MAP_H) - S1_MAX_EXITS)

//Stage 2 settings
#define STG2_MAP_W 6
#define STG2_MAP_H 9
#define STG2_MAX_EXITS 3
#define STG2_MAX_PIPES ((S2_MAP_W * S1_MAP_H) - S2_MAX_EXITS)

//Stage 3 settings
#define STG3_MAP_W 6
#define STG3_MAP_H 9
#define STG3_MAX_EXITS 4
#define STG3_MAX_PIPES ((S2_MAP_W * S2_MAP_H) - S2_MAX_EXITS)

#define Node_Space_W 5
#define Node_Space_H 5

#define SELECTOR_SPACE_COMPEN_W 4
#define SELECTOR_SPACE_COMPEN_H 4

enum GameState {

	nullState,
	endState,
	quitMenu,
	mainMenu,
	stage1,
	stage2,
	stage3,
	gameBeaten

};