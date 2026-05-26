
# Ejercicio de entrada/salida de números

Descripción
- Proyecto en C que procesa una lista de números desde un fichero de entrada y escribe el resultado en un fichero de salida.

Archivos
- [ejercicio.c](ejercicio.c): Código fuente en C.
- [numeros.txt](numeros.txt): Ejemplo de fichero de entrada con números.
- [resultado.txt](resultado.txt): Salida esperada o resultado generado.

Requisitos
- Compilador C (Microsoft cl.exe en Windows o `gcc` en sistemas Unix-like).

Compilación
- Windows con Visual Studio (cl.exe):

```powershell
cl.exe /EHsc /Zi /nologo /Fe:ejercicio.exe ejercicio.c
```

- Con GCC (Linux / MinGW):

```bash
gcc -std=c11 -O2 -Wall -o ejercicio ejercicio.c
```

Ejecución
- Ejecuta el binario generado y redirige o usa los ficheros de entrada/salida según el comportamiento del programa. Ejemplo si el programa lee de `numeros.txt` y escribe en `resultado.txt`:

Windows (PowerShell o CMD):

```powershell
.\ejercicio.exe
```

Linux / macOS:

```bash
./ejercicio
```

Formato de entrada
- `numeros.txt` debe contener la lista de números que el programa procesa. Puede ser una línea con números separados por espacios o varias líneas con un número por línea (dependiendo de la implementación en `ejercicio.c`).

Salida
- El programa escribe los resultados en `resultado.txt` (o en pantalla si está implementado así). Revisa el fichero [resultado.txt](resultado.txt) para ver un ejemplo del resultado esperado.


Autor
- Proyecto creado por el equipo del TP grupal.

Licencia
- Añade aquí la licencia que prefieras (por ejemplo, MIT) o indícame si quieres que la añada yo.

