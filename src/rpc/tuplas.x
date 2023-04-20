/*
Definición de la interfaz (XDR)
*/

const MAX_VALUE1 = 256;

program TUPLASPROG {
    version TUPLASPROGVER {
        int tuplas_init() = 0;  /* opcode 0 */
        int tuplas_set_value(int key, string value1<MAX_VALUE1>, int value2, double value3) = 1;
        int tuplas_get_value(int key, string value1<MAX_VALUE1>, int value2, double value3) = 2;
        int tuplas_modify_value(int key, string value1<MAX_VALUE1>, int value2, double value3) = 3;
        int tuplas_exist(int key) = 4;
        int tuplas_copy_key(int key1, int key2) = 5;
        int tuplas_delete_key(int key) = 6;
    } = 1;  /* version 1 */
} = 420;  /* program number */