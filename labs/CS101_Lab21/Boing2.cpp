#include "Console.h"

// Definition of the Scene struct type
struct Scene {
	// TODO: add fields
};

// Function prototypes
struct Scene scene_init(void);
void scene_render(struct Scene s);
struct Scene scene_update(struct Scene s);

// Animatation delay (.1s)
#define ANIMATION_DELAY (1000/10)

int main(void) {
	// NOTE: you don't need to change anything in the main() function

	struct Scene myScene;

	myScene = scene_init();

	int keep_going = 1;
	while (keep_going == 1) {
		// clear the off-screen display buffer
		cons_clear_screen();

		// render the scene into the display buffer
		scene_render(myScene);

		// copy the display buffer to the display
		cons_update();

		// pause
		cons_sleep_ms(ANIMATION_DELAY);

		// update the scene
		myScene = scene_update(myScene);

		// see if the user has pressed a key
		int key = cons_get_keypress();
		if (key != -1) {
			keep_going = 0;
		}
	}

	return 0;
}

struct Scene scene_init(void)
{
	struct Scene s;

	// TODO: initialize fields

	return s;
}

void scene_render(struct Scene s)
{
	// TODO: render the scene
}

struct Scene scene_update(struct Scene s)
{
	struct Scene result;

	// TODO: update the scene by assigning to the fields of "result"

	return result;
}
