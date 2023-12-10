#include <stdio.h>
#include <string.h>

int main() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char plaintext[100];
    char key[] = "deceptive";
    char ciphertext[100] = "";

    printf("Enter the plain text: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    int plaintext_number = 0;
    int key_number = 0;
    int ciphertext_number = 0;

    for (int i = 0; i < strlen(plaintext); i++) {
        for (int k = 0; k < 26; k++) {
            if (plaintext[i] == alphabet[k]) {
                plaintext_number = k;
                break;  
            }
        }

        for (int j = 0; j < 26; j++) {
            if (key[i % strlen(key)] == alphabet[j]) {
                key_number = j;
                break;  
            }
        }

        ciphertext_number = (plaintext_number + key_number) % 26;
        ciphertext[i] = alphabet[ciphertext_number];
    }

    printf("%s\n", ciphertext);

    return 0;
}

