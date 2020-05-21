//
// Created by Agus on 21/5/2020.
//

#include "HashFacade.h"

/**
 * Coloca un puntero a bloque en la tabla de hash
 * @param key coordenada del bloque
 * @param block puntero a colocar
 * @return
 */
bool Hash::put(Vector2 key, Block *block) {
    key = vectorTransform(key);
    if (table.all().find(Vector2Adaptor(key)) == table.all().end()) {
        table.all()[Vector2Adaptor(key)] = block;
        return true;
    }
    return false;
}

/**
 * Elimina el puntero de la tabla de hash y destruye el bloque
 * @param key coordenadas del bloque
 * @return
 */
bool Hash::remove(Vector2 key) {
    key = vectorTransform(key);
    if (table.all().find(Vector2Adaptor(key)) != table.all().end()) {
        table.all()[Vector2Adaptor(key)]->~Block();
        table.all().erase(Vector2Adaptor(key));
        return true;
    }
    return false;
}

/**
 * Busca un bloque en la tabla de hash y devuelve un puntero al mismo
 * @param key coordenadas del bloque
 * @return
 */
Block *Hash::get(Vector2 key) {
    key = vectorTransform(key);
    return table.all()[Vector2Adaptor(key)];
}

/**
 * Chequea si existe un bloque en la tabla de hash
 * @param key cordenadas del bloque
 * @return
 */
bool Hash::exists(Vector2 key) {
    key = vectorTransform(key);
    return table.all().find(Vector2Adaptor(key)) != table.all().end();
}
