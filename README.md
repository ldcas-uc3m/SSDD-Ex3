# Ejercicio Evaluable 3: RPC
By Luis Daniel Casais Mezquida & Lucía María Moya Sans  
Sistemas Distribuídos 22/23  
Bachelor's Degree in Computer Science and Engineering, grp. 89  
Universidad Carlos III de Madrid

## Descripción del ejercicio
Se desea diseñar e implementar el mismo servicio realizado en los ejercicios evaluable [1](https://github.com/ldcas-uc3m/SSDD-Ex1) y [2](https://github.com/ldcas-uc3m/SSDD-Ex2), pero en este caso utilizando o llamadas a procedimientos remotos (RPC). Para ello se utilizará el modelo ONC RPC visto en clase.  


El servicio permite almacenar tuplas `<clave-valor1-valor2-valor3>`. La clave será un número entero (`int`) y los valores asociados a la clave serán: una cadena de caracteres de cómo mucho 255 caracteres (excluido el código `0` que permite indicar el fin de la cadena), un número entero (`int`) y un número en coma flotante de doble precisión (`double`). Esta aplicación constará de un servidor que almacenará y gestionará las claves y de un API (_Application Programming Interface_) que permitirá a los procesos cliente del sistema hacer uso de los siguientes servicios:


- `int init()`: Esta llamada permite inicializar el servicio de elementos `clave-valor1-valor2-valor3`. Mediante este servicio se destruyen todas las tuplas que estuvieran almacenadas previamente. La función devuelve `0` en caso de éxito y `-1` en caso de error.
- `int set_value(int key, char *value1, int value2, double value3)`: Este servicio inserta el elemento `<key, value1, value2, value3>`. El servicio devuelve `0` si se insertó con éxito y `-1` en caso de error. Se considera error, intentar insertar una clave que ya existe previamente. En este caso se devolverá `-1` y no se insertará. También se considerará error cualquier error en las comunicaciones.
- `int get_value(int key, char *value1, int *value2, double *value3)`: Este servicio permite obtener los valores asociados a la clave `key`. Los valores se devuelven en `value1`, `value2` y `value3`. La función devuelve `0` en caso de éxito y `-1` en caso de error, por ejemplo, si no existe un elemento con dicha clave o si se produce un error de comunicaciones.
- `int modify_value(int key, char *value1, int value2, double value3)`: Este servicio permite modificar los valores asociados a la clave key. La función devuelve `0` en caso de éxito y `-1` en caso de error, por ejemplo, si no existe un elemento con dicha clave o si se produce un error en las comunicaciones.
- `int delete_key(int key)`: Este servicio permite borrar el elemento cuya clave es `key`. La función devuelve `0` en caso de éxito y `-1` en caso de error. En caso de que la clave no exista también se devuelve `-1`.
- `int exist(int key)`: Este servicio permite determinar si existe un elemento con clave key. La función devuelve `1` en caso de que exista y `0` en caso de que no exista. En caso de error se devuelve `-1`. Un error puede ocurrir en este caso por un problema en las comunicaciones.
- `int copy_key(int key1, int key2)`. Este servicio crea e inserta una nueva clave (`key2`) copiando los valores de la clave `key1` en la nueva clave creada (`key2`). En caso de que `key1` no exista se devolverá `-1` y no se creará la nueva clave. Si la clave `key2` no existe, se creará y se copiarán los valores de `key1` en `key2`. En caso de que la clave `key2` exista, se modificarán sus valores a partir de los de `key1`. La función devuelve `0` en caso de poder crear y copiar los nuevos datos en `key2` y `-1` en cualquier otro caso.

Tenga en cuenta para las llamadas anteriores que también se considera error, por ejemplo, Tenga en cuenta, para las llamadas anteriores, que también se considera error, por ejemplo, que se produzca un error en el sistema de RPCs.  

Todas las operaciones anteriores deben realizarse de forma atómica en el servidor.  

Diseñe e implemente, utilizando exclusivamente colas de mensajes POSIX y el lenguaje de programación C, el sistema que implemente este servicio de elementos `clave-valor1-valor2`. Para ello debe:

Diseñe e implemente, utilizando exclusivamente el lenguaje de programación C y el modelo de ONC RPC, el sistema que implementa este servicio de elementos `clave-valor1-valor2-valor3`. Para ello debe:
1. Diseñar y especificar la interfaz de servicio (archivo con extensión `.x`) que permite dar soporte a esta funcionalidad.
2. Desarrollar el código del servidor ([`servidor.c`](src/servidor.c)) encargado de gestionar las estructuras de datos que almacenan los elementos `clave-valor1-valor2-valor3`. Puede elegirse la estructura de datos que se estime oportuno, siempre que no imponga un límite en el número de elementos que se pueden almacenar. El servidor desarrollado debe ser concurrente.
3. Desarrollar el código que implementa los servicios anteriores (`init`, `set_value`, `get_value`, `delete_key`, `modify_value`, `exist`, y `copy_key`). El código se desarrollará sobre el archivo con nombre [`claves.c`](src/lib/claves.c). Este es el código que ofrece la interfaz a los clientes y se encarga de implementar los servicios anteriores (del lado del cliente) contactando con el servidor anterior. A partir de dicha implementación se deberá crear una biblioteca dinámica denominada `libclaves.so`. Esta será la biblioteca que utilizarán las aplicaciones de usuario que para usar el servicio. Debe investigar y buscar la forma de crear dicha biblioteca.
4. Desarrollar un ejemplo de código de un cliente ([`cliente.c`](src/cliente.c)) que utilice las funciones anteriores. El ejecutable de este programa tiene que generarse empleando la biblioteca desarrollada en el apartado anterior, es decir, el código de este cliente debe enlazarse con la biblioteca dinámica anterior. Este cliente se utilizará para probar el servicio desarrollado y deberá realizar las invocaciones al API de tuplas que considere oportuno. El código incluido en [`cliente.c`](src/cliente.c) solo podrá incluir llamadas a los servicios implementados y descritos anteriormente. En él no puede
haber ninguna referencia a servicios de RPC.
5. Elaborar un plan de pruebas del servicio desarrollado. Este plan se probará con el código desarrollado en el apartado anterior.

La estructura del código a desarrollar se muestra en la siguiente figura:  

![architecture_schema](img/fig1.png)

Para el almacenamiento de los elementos `clave-valor1-valor2-valor3` puede hacer uso de la estructura de datos o mecanismo de almacenamiento que considere más adecuado, el cual describirá en la memoria entregada. La estructura elegida no debe fijar un límite en el número de elementos que se pueden almacenar. Puede utilizarse la misma implementación realizada en el [ejercicio 1](https://github.com/ldcas-uc3m/SSDD-Ex1).  

El punto de partida para el desarrollo de este ejercicio es el [ejercicio 2](https://github.com/ldcas-uc3m/SSDD-Ex2) y el código desarrollado en el [laboratorio 4](https://github.com/ldcas-uc3m/SSDD-Labs/tree/main/lab4) dedicado al RPC.  

Se recomienda probar el servidor con varios clientes de forma concurrente.  

Un espeto importante a tener en cuenta en el desarrollo de este ejercicio es descubrir cómo integrar los archivos que se generan con el programa `rpcgen` para dar soporte a la funcionalidad descrita anteriormente. Por tanto, forma parte de este ejercicio el obtener la forma de integrar estos archivos en la solución final.

### Aclaraciones adicionales

En este ejercicio el cliente y la biblioteca a desarrollar tiene que conocer la dirección IP del servidor que ofrece el servicio de tuplas (para las RPC no es necesario conocer el puerto). Para evitar tener una dirección físicamente programada en el código y no tener que pasar la IP en la línea de mandatos del programa cliente, se va a considerar que la dirección IP se va a pasar utilizando la siguiente variable de entorno:
- `IP_TUPLAS`: variable de entorno que define la IP del servidor.

Esta variable de entorno habrá de definirse en cada terminal donde se ejecute el cliente. En cuanto al servidor, en este caso no será necesario pasarle en la línea de argumentos ningún puerto y este se ejecutará de la siguiente forma:

```bash
./servidor
```


## Instalación y ejecución

Compila con make:
```bash
cd src/
make
```

Al usar una librería dinámica, debes enlazarla:
```bash
export LD_LIBRARY_PATH=lib/
```

Para ejecutar el servidor:
```bash
./servidor
```

```bash
export IP_TUPLAS=localhost

./cliente
```
