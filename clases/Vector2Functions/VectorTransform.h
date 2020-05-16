//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_VECTORTRANSFORM_H
#define SQUARECRAFT_VECTORTRANSFORM_H

#include <raylib.h>
#include "../Player/Player.h"

/**
 * Recibe coordenadas en relación a la pantalla y las convierte para que estén en relación al jugador
 * @param v
 * @return
 */
Vector2 vectorTransform(Vector2 v);

#endif //SQUARECRAFT_VECTORTRANSFORM_H

