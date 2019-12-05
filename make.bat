REM must be run through a "Developer command prompt for VS 2017"
cl /W4 /EHsc src/encryption.cpp /link /out:build/encryption.exe
cl /W4 /EHsc src/decryption.cpp /link /out:build/decryption.exe