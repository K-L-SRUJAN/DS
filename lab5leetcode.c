bool backspaceCompare(char* s, char* t) {
    char sb1[1000] = ""; 
    char sb2[1000] = "";
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '#') {
            if (strlen(sb1) > 0) {
                sb1[strlen(sb1) - 1] = '\0';
            }
        } else {
            strncat(sb1, &s[i], 1);
        }
    }

    for (j = 0; t[j] != '\0'; j++) {
        if (t[j] == '#') {
            if (strlen(sb2) > 0) {
                sb2[strlen(sb2) - 1] = '\0';
            }
        } else {
            strncat(sb2, &t[j], 1);
        }
    }

    return strcmp(sb1, sb2) == 0;
}
