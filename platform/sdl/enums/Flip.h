/*
 * Flip.h
 *
 *  Created on: Dec 28, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_FLIP_H_
#define SDL_GRAPHICS_FLIP_H_


enum Flip {
	NONE = 0x00000000,     /**< Do not flip */
	HORIZONTAL = 0x00000001,    /**< flip horizontally */
	VERTICAL = 0x00000002     /**< flip vertically */
};

#endif /* SDL_GRAPHICS_FLIP_H_ */
