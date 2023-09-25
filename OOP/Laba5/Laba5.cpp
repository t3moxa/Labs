#include <iostream>
#include <cstdio>
#include <errno.h>
#include <string>
#include <IO.h>

using namespace std;
char c1, comp[26], ecode, ecode2, key[26],keyn[26];
int n, i = 0, g, mx = 0, mxi, nmx = 0, nmxi, NO = 0, ch,tekmax = 0;
int num[51];
int lng[51];
string str[51];
int main()
{
        FILE* fin, * fout1, * fout2;
        const char* filename = "test.txt";
        const char* fileout1name = "important.txt";
        const char* fileout2name = "long.txt";
        setlocale(LC_ALL, "Russian");
        fin = fopen(filename, "r");
        while ((ecode = fscanf(fin, "%s", key)) != EOF) {
            g += 1;
            lng[g] = strlen(key);
            str[g] = key;
        }
        g += 1;
        for (i = 0; i < g; ++i)
        {
            strcpy(key, str[i].c_str());
            for (n = 0; n < g; ++n)
            {
                strcpy(keyn, str[n].c_str());
                if ((strncmp(key, keyn, lng[i])) == 0)
                    num[i] += 1;
            }
        }
        for (i = 1; i < g; ++i)
        {
            if (num[i] > mx)
            {
                mx = num[i];
                mxi = i;
            }
        }
        if (mx == 1)
            NO = 1;
        for (i = 1; i < g; ++i)
        {
            if ((lng[i] > nmx) & (num[i] > 1))
            {
                nmx = lng[i];
                nmxi = i;
            }
        }
        if ((fout1 = fopen(fileout1name, "w")) != NULL) {
            if (NO == 0)
            {
                strcpy(key, str[mxi].c_str());
                fprintf(fout1, "Самое важное корневое слово - %s\n", key);
                fprintf(fout1, "Количество повторений - %d\n", mx - 1);
            }
            else
                fprintf(fout1, "NO");
        }
        if ((fout2 = fopen(fileout2name, "w")) != NULL) {
            if (NO == 0)
            {
                strcpy(key, str[nmxi].c_str());
                fprintf(fout2, "Самое длинное корневое слово - %s\n", key);
                fprintf(fout2, "Слова, для которых оно является корневым: \n");
                for (n = 1; n < g; ++n)
                {
                    strcpy(keyn, str[n].c_str());
                    if (((strncmp(key, keyn, lng[nmxi])) == 0) & (strlen(key) < strlen(keyn)))
                        fprintf(fout2, "%s\n", keyn);
                }
            }
            else
                fprintf(fout2, "NO");
        }
        fclose(fout1);
        fclose(fout2);


        mx = 0;
        mxi = 0;
        nmx = 0;
        nmxi = 0;
            for (i = 1; i < g; ++i)
            {
                strcpy(key, str[i].c_str());
                for (n = 1; n < g; ++n)
                {
                    strcpy(keyn, str[n].c_str());
                    if ((strncmp(key, keyn, strlen(key))) == 0)
                        tekmax += 1;
                }
                if (tekmax > mx)
                {
                    mx = tekmax;
                    mxi = i;
                }
                if ((strlen(key) > nmx)&(tekmax>1))
                {
                    nmx = strlen(key);
                    nmxi = i;
                }
                tekmax = 0;
            }
            cout << "Самое важное корневое слово - " << str[mxi] << "\n";
            cout << "Кол-во слов, для которых оно корневое - " << mx-1 << "\n";
            cout << "Самое длинное корневое слово - " << str[nmxi] << "\n";
            cout << "Слова, для которых оно корневое: " << "\n";
            strcpy(key, str[nmxi].c_str());
            for (n = 1; n < g; ++n)
            {
                strcpy(keyn, str[n].c_str());
                if (((strncmp(key, keyn, strlen(key))) == 0) & (strlen(key) < strlen(keyn)))
                    cout << keyn << "\n";
            }
        fclose(fin);
}
