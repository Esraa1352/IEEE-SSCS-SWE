#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sms.h"
#include"load_users.h"
int load_users() {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        // File might not exist yet, treat as empty user list
        return 0;
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        // Parse CSV line like: "name","email","hashed_password","role"

        Data user;
        char role_str[20];

        // sscanf with %[^"] to extract quoted strings
        int scanned = sscanf(line, "\"%[^\"]\",\"%[^\"]\",\"%[^\"]\",\"%[^\"]\"",
                             user.name, user.email, user.hashed_password, role_str);
        if (scanned == 4) {
            // Convert role string to enum index
            if (strcmp(role_str, "ADMIN") == 0) {
                user.role = 0;
            } else if (strcmp(role_str, "MODERATOR") == 0) {
                user.role = 1;
            } else {
                user.role = 2; // USER
            }

            // Reallocate and store user
            Data *tmp = realloc(users, sizeof(Data) * (users_count + 1));
            if (!tmp) {
                perror("Failed to load users in memory");
                fclose(file);
                return -1;
            }
            users = tmp;
            users[users_count] = user;
            users_count++;
        }
    }
    fclose(file);
    return 0;
}
