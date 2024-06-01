#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    char* str;
    size_t length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        if (s) {
            length = strlen(s);
            str = new char[length + 1];
            strcpy_s(str, length + 1, s);
        }
        else {
            str = nullptr;
            length = 0;
        }
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy_s(str, length + 1, other.str);
        }
        return *this;
    }

    size_t getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        char* newStr = new char[length + other.length + 1];
        strcpy_s(newStr, length + 1, str);
        strcat_s(newStr, length + other.length + 1, other.str);

        String newString(newStr);
        delete[] newStr;
        return newString;
    }

    String& operator+=(const String& other) {
        char* newStr = new char[length + other.length + 1];
        strcpy_s(newStr, length + 1, str);
        strcat_s(newStr, length + other.length + 1, other.str);

        delete[] str;
        str = newStr;
        length += other.length;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const String& string) {
        if (string.str) {
            os << string.str;
        }
        return os;
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) : String() {
        if (isValidBitString(s)) {
            length = strlen(s);
            str = new char[length + 1];
            strcpy_s(str, length + 1, s);
        }
        else {
            str = nullptr;
            length = 0;
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        if (this != &other) {
            String::operator=(other);
        }
        return *this;
    }

    ~BitString() {}

    void negate() {
        if (str && length > 0) {
            for (size_t i = 0; i < length; i++) {
                str[i] = (str[i] == '0') ? '1' : '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        BitString result(*this);
        result += other;
        return result;
    }

    BitString& operator+=(const BitString& other) {
        if (isValidBitString(other.str)) {
            String::operator+=(other);
        }
        else {
            clear();
        }
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }

private:
    bool isValidBitString(const char* s) const  {
        if (!s) return false;
        for (size_t i = 0; i < strlen(s); i++) {
            if (s[i] != '0' && s[i] != '1') {
                return false;
            }
        }
        return true;
    }
};

int main() {
    String s1("Hello");
    String s2(" World!");
    String s3 = s1 + s2;
    cout << "Concatenation of s1 and s2: " << s3 << endl;

    BitString bs1("1010");
    BitString bs2("0110");
    BitString bs3 = bs1 + bs2;
    cout << "Concatenation of bs1 and bs2: " << bs3 << endl;

    bs1.negate();
    cout << "Negation of bs1: " << bs1 << endl;

    cout << "Are bs1 and bs3 equal? " << (bs1 == bs3 ? "Yes" : "No") << endl;
    cout << "Are bs1 and bs2 unequal? " << (bs1 != bs2 ? "Yes" : "No") << endl;
    return 0;
}