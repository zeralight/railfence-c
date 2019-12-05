# Compilation and Running
## Linux
### Encryption
make clean
make encryption
./build/encryption  -n "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES." -d 4 -r 5
*'CYLIETSTGENC AEUEERRCLMU OPYAICE  SRIPAOSTSTN TEECID  IDPYDONDEAVR NCHAEHSTOFRCT EOSI TFNIN QD HHIARFORPU.S  OEUE ER  CIS RTMLAC'*

### Decryption
make clean
make decryption
./build/decryption -n "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK" -d 3 -r 3
*'THE RAILFENCE CIPHER IS AN EASY TO APPLY TRANSPOSITION CIPHER THAT JUMBLES UP THE ORDER OF THE LETTERS OF A MESSAGE IN A QUICK CONVENIENT WAY IT ALSO HAS THE SECURITY OF A KEY TO MAKE IT A LITTLE BIT HARDER TO BREAK'*

### Automated tests
make clean
make tests

## Windows
From a Developer Console:
make.bat
cd build

### Encryption
encryption.exe -n "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES." -d 4 -r 5
*'CYLIETSTGENC AEUEERRCLMU OPYAICE  SRIPAOSTSTN TEECID  IDPYDONDEAVR NCHAEHSTOFRCT EOSI TFNIN QD HHIARFORPU.S  OEUE ER  CIS RTMLAC'*

### Decryption
decryption.exe -n "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK" -d 3 -r 3
*'THE RAILFENCE CIPHER IS AN EASY TO APPLY TRANSPOSITION CIPHER THAT JUMBLES UP THE ORDER OF THE LETTERS OF A MESSAGE IN A QUICK CONVENIENT WAY IT ALSO HAS THE SECURITY OF A KEY TO MAKE IT A LITTLE BIT HARDER TO BREAK'*


# Encryption algorithm
## Input:
**n**: Plain text
**d**: number of rows of the table
**r**: number of repetitions 

## Algorithm
1) Allocate a 2D array of **d** rows and **length(plain text)** columns.
2) Repeat **r** times 3) to 4).
3) initialize the 2D array with 0's ; Assuming plain text doesn't have any 0.
4)  [i = 0, j = 0, p = 1] 
    foreach c in **plain**:
        **array**[ i ][ j ] <-- c
        j += 1
        if i + 1 == rows then p <-- -1 ; Switch direction to up
        else if i == 0 then p <-- 1  ; Switch direction to down
        i += p
5)  **res** <-- ""
    foreach i in [0, rows):
        foreach j in [0, **length(plain text)**):
            if **array**[ i ][ j ] != 0 then
                **res** <-- res + array[ i ][ j ]
            end if
6) return **res**


# Decryption algorithm
## Input:
**n**: cipher text
**d**: number of rows of the table
**r**: number of repetitions 

## Algorithm
1) Allocate a 2D array of **d** rows and **length(cipher)** columns.
2) Repeat **r** times:
3) Do Step 3) and 4) of Encryption with Plain a 1's String with the same length as Cipher.
4)  [n <-- 0]
    foreach i in [0, rows):
        foreach j in [0, **length(plain text)**):
            if **array**[ i ][ j ] != 0 then
                **array**[ i ][ j ] <-- cipher[n]
                n += 1
            end if
        end for
    end for
5)  Do Step 4) of Encryption but swapping the assignment
    c <-- **array**[ i ][ j ]
6) return calculated plain string in 5).