#include "app.h"

int main() {
	/*
	 *initialize the engine, this call 
	 *should register all the libs
	 */

	init_engine();
	
	/*
	 * Now list down the capabilities of
	 * the library. The handle is hearby 
	 * given the li.
	 */

	engine_cap();

}	
