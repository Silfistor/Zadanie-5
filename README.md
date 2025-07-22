Во 2 задание нужно скомпилировать файл program.c : 
gcc -fno-stack-protector -no-pie -o program program.c 
После создание файла для переполнения пароля exploit.py 
Запускаем программу ./program < input.bin
