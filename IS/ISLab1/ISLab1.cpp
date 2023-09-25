#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>

using namespace std;

string lleg[4] = {"C++", "Java", "Javascript", "Python"};
string sleg[5] = {"Веб-разработка", "Мобильная разработка", "GameDev", "Базы данных", "DevOps"};
string cleg1[3] = {"Москва", "Санкт-Петербург", "Казань"};
string cleg2[6] = {"Архангельск", "Владивосток", "Екатеринбург", "Саратов", "Волгоград", "Новосибирск"};
string firms[5] = { "Rubius", "General Atomics", "Тинькофф", "Газпром", "Яндекс" };
int qnum = 1;
string RandomCity(int key)
{
    string City;
    int i;
    if (key==1)
        City = "Томск";
    if (key==2)
    {
        i = rand()%3;
        City = cleg1[i];
    }
    if (key==3)
    {
        i = rand()%6;
        City = cleg2[i];
    }
    return City;    
}
string RandomName()
{
    return firms[rand() % 5];
}
class Vacancy
{
public:
    string name, locname;
    float wage, experience;
    int location;
    int languages[4];
    int skills[5];
    static Vacancy randomizeVacancy()
    {
        Vacancy bruh;
        bruh.experience = rand() % 5;
        bruh.location = (rand() % 3) + 1;
        bruh.locname = RandomCity(bruh.location);
        for (int i = 0; i < 4; i++)
        {
            if ((rand()%2)>0)
                bruh.languages[i] = 1;
            else
                bruh.languages[i] = 0;
        }
        for (int i = 0; i < 5; i++)
        {
            if ((rand() % 2) > 0)
                bruh.skills[i] = 1;
            else
                bruh.skills[i] = 0;
        }
        bruh.wage = (rand() % 100) * 2500;
        bruh.name = RandomName();
        return bruh;
    }
    Vacancy() :wage(0), experience(0), location(0), skills {0,0,0,0,0}, languages {0,0,0,0}
    {

    }
    ~Vacancy()
    {
    }
    static void ShowVacancy(Vacancy vac)
    {
        if (vac.name!="0")
            cout<<"Фирма: "<<vac.name<<endl;
        cout<<"Расположение: ";
        cout<<vac.locname<<endl;
        cout<<"Требуемые языки программирования: ";
        for(int i=0;i<4;i++)
        {
            if (vac.languages[i])
                cout<<lleg[i]<<" ";
        }
        cout<<endl;
        cout<<"Требуемые знания: ";
        for(int i=0;i<5;i++)
        {
            if (vac.skills[i])
                cout<<sleg[i]<<" ";
        }
        cout<<endl;
        cout << "Требуемый стаж: ";
        cout << vac.experience << endl;
        cout<<"Начальная зарплата: ";
        cout<<vac.wage<<"\n\n";
    }

    static bool isSetForVacancy(Vacancy vac1, Vacancy vac2) //слева идеальная, справа должность на которую проверяем
    {
        bool skill = 1, lang = 1, exp = 1;
        for (int i = 0; i<4;i++)
        { 
            if (vac1.languages[i] < vac2.languages[i])
            {
                lang = 0;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            if (vac1.skills[i] < vac2.skills[i])
            {
                skill = 0;
            }
        }
        if (vac1.experience < vac2.experience)
            exp = 0;
        return (lang * skill * exp);
    }
    static int findBest(Vacancy vac1, Vacancy vac2)
    {
        int result = vac2.wage - vac1.wage;
        if (vac1.location = vac2.location)
            result += abs(result) / 2;
        else
            result -= abs(result) / 2;
        return result;
    }
};

void question(string text)
{
    cout << "Вопрос №" << qnum << ":\n" << text;
    qnum+=1;
}
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    Vacancy IdealVacancy;
    IdealVacancy.name = "0";
    int IdealLanguage, IdealSkills, i;
    Vacancy* Vc = new Vacancy[10];
    for (i = 0; i < 10; i++)
    {
        Vc[i] = Vacancy::randomizeVacancy();
    }
    for (i = 0; i < 10; i++)
    {
        Vacancy::ShowVacancy(Vc[i]);
    }
    cout << "Добро пожаловать в экспертную систему по выбору места работы после окончания ИПМКН ТГУ.\n";
    cout << "Для начала необходимо пройти опрос, чтобы система сформировала ваши предпочтения.\n";
    cout << "Чтобы ответить на вопрос, необходимо ввести цифру, соответствующую выбранному вами варианту ответа, или ввести сам ответ.\n\n";
    question("Где бы вы хотели работать?\n1 - Томск\n2 - Центр России (Москва и т.д.)\n3 - Любой город России\n");
    cin >> IdealVacancy.location;
    question("Какими языками программирования из представленных вы владеете?\n(можно выбрать несколько вариантов)\n1 - C++\n2 - Java\n3 - Javascript\n4 - Python\n");
    for (i = 0;i<4;i++)
    {
        cin >> IdealLanguage;
        IdealVacancy.languages[IdealLanguage - 1] = 1;
        if (cin.peek() == '\n')
        break;
    }
    cout << flush;
    question("Навыками в каких сферах программирования вы обладаете?\n(можно выбрать несколько вариантов)\n1 - Веб-разработка\n2 - Мобильная разработка\n3 - GameDev\n4 - Базы данных\n5 - DevOps\n");
    for (i = 0;i<5;i++)
    {
        cin >> IdealSkills;
        IdealVacancy.skills[IdealSkills - 1] = 1;
        if (cin.peek() == '\n')
        break;
    }
    question("Какой опыт работы у вас уже есть (в годах)?\n");
    cin >> IdealVacancy.experience;
    question("Какая минимальная зарплата вас устроит (в рублях)?\n");
    cin >> IdealVacancy.wage;
    int k = 0;
    int* VcIndex = new int[10];
    for (i = 0; i < 10; i++)
    {
        VcIndex[i] = -1;
    }
    cout << endl << "Подходящие вашим возможностям вакансии:" << endl;
    for (i = 0; i < 10; i++)
    {
        if (Vacancy::isSetForVacancy(IdealVacancy, Vc[i]))
        {
            VcIndex[k] = i;
            Vacancy::ShowVacancy(Vc[i]);
            k++;
        }
    }
    k = 0;
    cout << endl << "Из них наиболее подходящая вашим запросам: " << endl;
    int maxscore = 0; int maxk = -1;
    while (VcIndex[k] >= 0)
    {
        if (Vacancy::findBest(IdealVacancy, Vc[VcIndex[k]]) > maxscore)
        {
            maxscore = Vacancy::findBest(IdealVacancy, Vc[VcIndex[k]]);
            maxk = k;
        }
        k++;
    }
    if (maxk > -1)
        Vacancy::ShowVacancy(Vc[VcIndex[maxk]]);
    else
        cout << "Подходящей вакансии не найдено!";
}