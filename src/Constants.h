#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

namespace sg {

    const unsigned int WINDOW_WIDTH = 1200;
    const unsigned int WINDOW_HEIGHT = 800;

    enum LayerType {
        TILEMAP_LAYER = 0,
        VEGETATION_LAYER = 1,
        ENEMIES_LAYER = 2,
        PLAYER_LAYER = 3,
        PROJECTILE_LAYER = 4,
        UI_LAYER = 5
    };

    const unsigned int NUM_LAYERS = 6;

}

#endif // CONSTANTS_H_INCLUDED
