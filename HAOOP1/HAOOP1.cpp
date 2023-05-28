#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//Задание 1:
class Divide {
private:
	int a;
	int b;
	int absDiv(int x, int y) {
		if (y == 0)
			return x;
		return absDiv(y, x % y);
	}
public:
	void input(int c, int z) {
		a = c;
		b = z;
	}
	void mult(int x) {
		a *= x;
		std::cout << "Дробь:  " << a << '/' << b << std::endl;
	}
	void div(int x) {
		b *= x;
		std::cout << "Дробь:  " << a << '/' << b << std::endl;

	}
	void sum(int x) {
		a += (x * b);
		std::cout << "Дробь:  " << a << '/' << b << std::endl;
	}
	void sub(int x) {
		a -= (x * b);
		std::cout << "Дробь:  " << a << '/' << b << std::endl;

	}
	void show() {
		std::cout << "Текущая дробь:  " << a << '/' << b << std::endl;
	}
	int peredacha() {
		return absDiv(a, b);
	}
	void reduct(int x) {
		a /= x;
		b /= x;
	}
};

//Задание 2:
class Subscriber {
    char* surname;
    char* name;
    char* secondName;
public:
    Subscriber() : Subscriber{ "Surname","Name","Second name" } {}
    Subscriber(const char* surnameP, const char* nameP, const char* secondNameP) :
        surname{ initSurname(surnameP) }, name{ initName(nameP) }, secondName{ initSecondName(secondNameP) } {}

    Subscriber(const Subscriber& object) :
        surname{ initSurname(object.surname) }, name{ initName(object.name) }, secondName{ initSecondName(object.secondName) } {}

    Subscriber& setSurname(const char* surnameP);
    Subscriber& setName(const char* nameP);
    Subscriber& setSecondName(const char* secondNameP);

    char* initSurname(const char* surnameP);
    char* initName(const char* nameP);
    char* initSecondName(const char* secondNameP);

    Subscriber& init(const char* surnameP, const char* nameP, const char* secondNameP);

    const char* getSurname()const { return surname; }
    const char* getName()const { return name; }
    const char* getSecondName()const { return secondName; }

    Subscriber& print();

    ~Subscriber() { delete[] surname; delete[] name; delete[] secondName; }
};

Subscriber& Subscriber::setSurname(const char* surnameP) {
    auto len{ strlen(surnameP) + 1 };
    if (!surname) { surname = new char[len]; }
    else if (surname and strlen(surname) + 1 < len) {
        delete[] surname;
        surname = new char[len];
    }
    strcpy_s(surname, len, surnameP);
    return *this;
}

Subscriber& Subscriber::setName(const char* nameP)
{
    auto len{ strlen(nameP) + 1 };
    if (!name) { name = new char[len]; }
    else if (name and strlen(name) + 1 < len) {
        delete[] name;
        name = new char[len];
    }
    strcpy_s(name, len, nameP);
    return *this;
}

Subscriber& Subscriber::setSecondName(const char* secondNameP) {
    auto len{ strlen(secondNameP) + 1 };
    if (!secondName) { secondName = new char[len]; }
    else if (secondName and strlen(secondName) + 1 < len) {
        delete[] secondName;
        secondName = new char[len];
    }
    strcpy_s(secondName, len, secondNameP);
    return *this;
}

char* Subscriber::initSurname(const char* surnameP) {
    surname = { new char[strlen(surnameP) + 1] };
    strcpy_s(surname, strlen(surnameP) + 1, surnameP);
    return surname;
}
char* Subscriber::initName(const char* NameP) {
    name = { new char[strlen(NameP) + 1] };
    strcpy_s(name, strlen(NameP) + 1, NameP);
    return name;
}
char* Subscriber::initSecondName(const char* secondNameP) {
    secondName = { new char[strlen(secondNameP) + 1] };
    strcpy_s(secondName, strlen(secondNameP) + 1, secondNameP);
    return secondName;
}

Subscriber& Subscriber::init(const char* surnameP, const char* nameP, const char* secondNameP) {
    setSurname(surnameP);
    setName(nameP);
    setSecondName(secondNameP);
    return *this;
}

Subscriber& Subscriber::print() {
    std::cout << "\033[1;32m" << "Фамилия: " << "\033[0m" << surname
        << "\033[1;32m" << "\nИмя: " << "\033[0m" << name << "\nОтчество: " << secondName << '\n';
    return *this;
}

class PhoneBook
{
    Subscriber contact;
    long long homePhone;
    long long workPhone;
    long long mobilePhone;
    char* addContactDetails;

public:
    PhoneBook() : PhoneBook{ "test", "test","test", 0,0,0,"test" } {}
    PhoneBook(const char* surnameP, const char* nameP, const char* secondNameP, long long homePhoneP, long long workPhoneP, long long mobilePhoneP, const char* addContactDetailsP) :
        contact{ surnameP,nameP,secondNameP }, homePhone{ homePhoneP }, workPhone{ workPhoneP }, mobilePhone{ mobilePhoneP }, addContactDetails{ initContactDetailsP(addContactDetailsP) } {}
    PhoneBook(const PhoneBook& contacts) :
        contact{ contacts.contact }, homePhone{ contacts.homePhone }, workPhone{ contacts.workPhone }, mobilePhone{ contacts.mobilePhone }, addContactDetails{ initContactDetailsP(contacts.addContactDetails) } {}

    PhoneBook& setContacts(const char* surnameP, const char* nameP, const char* secondNameP)
    {
        contact.setSurname(surnameP); contact.setName(nameP); contact.setSecondName(secondNameP); return *this;
    }

    PhoneBook& setHomePhone(long long homePhoneP) { homePhone = homePhoneP; return *this; }
    PhoneBook& setWorkPhone(long long workPhoneP) { workPhone = workPhoneP; return *this; }
    PhoneBook& setMobilePhone(long long mobilePhoneP) { mobilePhone = mobilePhoneP; return *this; }

    PhoneBook& setContactDetails(const char* addContactDetailsP);

    const char* getContactSurname()const { return contact.getSurname(); }
    const char* getContactName()const { return contact.getName(); }
    const char* getContactSecondName()const { return contact.getSecondName(); }

    long long getHomePhone()const { return homePhone; }
    long long getWorkPhone()const { return workPhone; }
    long long getMobilePhone()const { return mobilePhone; }

    const char* getaddContactDetails()const { return addContactDetails; }

    char* initContactDetailsP(const char* addContactDetailsP);

    PhoneBook& init(const char* surnameP, const char* nameP, const char* secondNameP, long long homePhoneP, long long workPhoneP, long long mobilePhoneP, const char* addContactDetailsP);

    PhoneBook& print();

    ~PhoneBook() { delete[] addContactDetails; }
};

PhoneBook& PhoneBook::setContactDetails(const char* addContactDetailsP)
{
    auto len{ strlen(addContactDetailsP) + 1 };
    if (!addContactDetails) { addContactDetails = new char[len]; }
    else if (addContactDetails and strlen(addContactDetails) + 1 < len)
    {
        delete[] addContactDetails;
        addContactDetails = new char[len];
    }
    strcpy_s(addContactDetails, len, addContactDetailsP);
    return *this;
}

char* PhoneBook::initContactDetailsP(const char* addContactDetailsP)
{
    addContactDetails = { new char[strlen(addContactDetailsP) + 1] };
    strcpy_s(addContactDetails, strlen(addContactDetailsP) + 1, addContactDetailsP);
    return addContactDetails;
}

PhoneBook& PhoneBook::init(const char* surnameP, const char* nameP, const char* secondNameP, long long homePhoneP, long long workPhoneP, long long mobilePhoneP, const char* addContactDetailsP)
{
    setContacts(surnameP, nameP, secondNameP);
    homePhone = homePhoneP;
    workPhone = workPhoneP;
    mobilePhone = mobilePhoneP;
    setContactDetails(addContactDetailsP);
    return *this;
}

PhoneBook& PhoneBook::print()
{
    contact.print();
    std::cout << "Домашний телефон: " << homePhone << "\nРабочий телефон: " << workPhone << "\nМобильный телефон: " << mobilePhone
        << "\nДополнительная информация: " << addContactDetails << '\n';
    return *this;
}

void listPhoneBook(PhoneBook* begin, PhoneBook* end)
{
    for (auto contacts{ begin }; contacts != end; ++contacts)
        contacts->print(); std::cout << '\n';
}

void contactSearch(PhoneBook* begin, PhoneBook* end, char* found, bool(*searchCriterion)(const PhoneBook& const contacts, char* found))
{
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        if (searchCriterion(*contacts, found)) { contacts->print(); std::cout << '\n'; }
    }
}

bool searchBySurname(const PhoneBook& const contacts, char* found)
{
    return strstr(contacts.getContactSurname(), found);
}

bool searchByName(const PhoneBook& const contacts, char* found)
{
    return strstr(contacts.getContactName(), found);
}

void savePhoneBook(PhoneBook* begin, PhoneBook* end)
{
    std::ofstream outf;
    outf.open("PhoneBook.txt");
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        outf << contacts->getContactSurname() << '\n';
        outf << contacts->getContactName() << '\n';
        outf << contacts->getContactSecondName() << '\n';
        outf << contacts->getHomePhone() << '\n';
        outf << contacts->getWorkPhone() << '\n';
        outf << contacts->getMobilePhone() << '\n';
        outf << contacts->getaddContactDetails() << '\n';
    }
    outf.close();
}

void loadPhoneBook(PhoneBook* begin, PhoneBook* end)
{
    std::ifstream inf;
    char surnameP[15];
    char nameP[15];
    char secondNameP[15];
    long long homePhoneP{ 0 };
    long long workPhoneP{ 0 };
    long long mobilePhoneP{ 0 };
    char contactDetailsP[15];

    inf.open("PhoneBook.txt");
    for (auto contacts{ begin }; contacts != end; ++contacts)
    {
        inf.getline(surnameP, 15);
        inf.getline(nameP, 15);
        inf.getline(secondNameP, 15);
        inf >> homePhoneP;
        inf >> workPhoneP;
        inf >> mobilePhoneP;
        inf.ignore(100, '\n');
        inf.getline(contactDetailsP, 15);
        contacts->init(surnameP, nameP, secondNameP, homePhoneP, workPhoneP, mobilePhoneP, contactDetailsP);
    }
    inf.close();
}

void pastInArr(PhoneBook*& Arr, size_t& arrSize, size_t idxPastElem)
{
    PhoneBook* newArr{ new PhoneBook[arrSize + 1] };
    for (size_t i{ 0 }; i < arrSize; ++i)
    {
        newArr[i + (i >= idxPastElem)].PhoneBook::PhoneBook(Arr[i]);
    }
    delete[] Arr;
    Arr = newArr;
    arrSize++;
}

void cutFromArr(PhoneBook*& Arr, size_t& arrSize, size_t idxCutElem)
{
    PhoneBook* newArr{ new PhoneBook[arrSize--] };
    for (size_t i{ 0 }; i < arrSize; ++i)
    {
        newArr[i].PhoneBook::PhoneBook(Arr[i + (i >= idxCutElem)]);
    }
    delete[]Arr;
    Arr = newArr;
}

void phoneBookSort(PhoneBook* contacts, size_t PhoneBookSize, bool(*criteria)(const PhoneBook& contactsA, const PhoneBook& contactsB))
{
    PhoneBook tmp;
    for (size_t head{ 0 }; head < PhoneBookSize; ++head)
    {
        for (size_t tail{ PhoneBookSize - 1 }; tail > head; --tail)
        {
            if (criteria(contacts[tail], contacts[head]))
            {
                tmp.PhoneBook::PhoneBook(contacts[tail]);
                contacts[tail].PhoneBook::PhoneBook(contacts[head]);
                contacts[head].PhoneBook::PhoneBook(tmp);
            }
        }
    }
}

bool sortBySurname(const PhoneBook& contactsA, const PhoneBook& contactsB)
{
    return strcmp(contactsA.getContactSurname(), contactsB.getContactSurname()) < 0;
}

bool sortByName(const PhoneBook& contactsA, const PhoneBook& contactsB)
{
    return strcmp(contactsA.getContactName(), contactsB.getContactName()) < 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
//Задание 1.
	int a, b, m;
	char c = 'y';
	std::cout << "Введите числитель: " << std::endl;
	std::cin >> a;
	std::cout << "Введите знаменатель: " << std::endl;
	std::cin >> b;
	Divide obj;
	obj.input(a, b);
	do {
		obj.reduct(obj.peredacha());
		obj.show();
		std::cout << "1: Прибавить к дроби число" << std::endl;
		std::cout << "2: Отнять от дроби число" << std::endl;
		std::cout << "3: Умножить дробь на число" << std::endl;
		std::cout << "4: Разделить дробь на число" << std::endl;
		std::cout << "Выберите действие -> ";
		std::cin >> m;
		switch (m)
		{
		case 1:
			std::cout << "Введите слагаемое: " << std::endl;
			std::cin >> a;
			obj.sum(a);
			break;
		case 2:
			std::cout << "Введите вычитаемое: " << std::endl;
			std::cin >> a;
			obj.sub(a);
			break;
		case 3:
			std::cout << "Введите множитель" << std::endl;
			std::cin >> a;
			obj.mult(a);
			break;
		case 4:
			std::cout << "Введите делитель" << std::endl;
			std::cin >> a;
			obj.div(a);
			break;
		default:
			std::cout << "Ошибка ввода!" << std::endl;
		}
		std::cout << "Продолжить работу?(y/n)" << std::endl;
		std::cin >> c;
	} while (c != 'n');
//Задание 2.
    size_t PhoneBookSize{ 10 };
    PhoneBook* contacts{ new PhoneBook[PhoneBookSize] };
    auto contactsEnd{ contacts + PhoneBookSize };

    contacts[0].init("Свидригайлов", "Аркадий", "Иванович", 0, 0, 9122231701, " ");
    contacts[1].init("Курагина", "Елена", "Васильевна", 0, 0, 9193564575, " ");
    contacts[2].init("Базаров", "Евгений", "Васильевич", 0, 0, 9026756455, " ");
    contacts[3].init("Безухов", "Петр", "Кириллович", 0, 0, 9192456988, "Друг");
    contacts[4].init("Ростова", "Наталья", "Ильина", 495221321, 4950231705, 9827777773, "Директор");
    contacts[5].init("Хвостов", "Олег", "Васильевич", 0, 4956225565, 9829638521, " ");
    contacts[6].init("Безухов", "Анатолий", "Петрович", 0, 4952225533, 9120996523, " ");
    contacts[7].init("Болконский", "Андрей", "Николаевич", 4952228511, 4952231799, 9197412525, "Механик");
    contacts[8].init("Ростовская", "Наталья", "Андреевна", 4952221300, 0, 9127894532, " ");
    contacts[9].init("Раскольников", "Родион", "Романович", 4952221515, 4952231755, 9821030303, "Семейный доктор");

    listPhoneBook(contacts, contactsEnd);

    char foundS[]{ "Безухов" };
    std::cout << "\033[1;31m" << "\nПоиск по фамилии:\n" << "\033[0m";
    contactSearch(contacts, contactsEnd, foundS, searchBySurname);

    char foundN[]{ "Андрей" };
    std::cout << "\033[1;31m" << "\nПоиск по имени:\n" << "\033[0m";
    contactSearch(contacts, contactsEnd, foundN, searchByName);

    savePhoneBook(contacts, contactsEnd);

    std::cout << "\033[1;31m" << "\nЗагрузка контактов:\n" << "\033[0m";
    PhoneBook* fileContacts{ new PhoneBook[PhoneBookSize] };
    auto fileContactsEnd{ fileContacts + PhoneBookSize };
    loadPhoneBook(fileContacts, fileContactsEnd);
    listPhoneBook(fileContacts, fileContactsEnd);

    std::cout << "\033[1;31m" << "\nДобавить контакт:\n" << "\033[0m";
    pastInArr(contacts, PhoneBookSize, 3);
    contacts[3].init("Демидова", "Ольга", "Сергеевна", 0, 0, 9192582525, "Работник");
    listPhoneBook(contacts, contacts + PhoneBookSize);

    std::cout << "\033[1;31m" << "\nУдалить контакт:\n" << "\033[0m";
    cutFromArr(contacts, PhoneBookSize, 3);
    listPhoneBook(contacts, contacts + PhoneBookSize);

    phoneBookSort(contacts, PhoneBookSize, sortBySurname);
    std::cout << "\033[1;31m" << "\nСортировать по фамилии:\n" << "\033[0m";
    listPhoneBook(contacts, contacts + PhoneBookSize);

    delete[] contacts;

	return 0;
}