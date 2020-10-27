#include <cassert>
#include <iostream>


template <typename T>
bool is_prime(T num) {
    bool result = true;
    if (num <= 1) {
        return 0;
    } else if (num == 2) {
        return 1;
    } else if ((num & 1) == 0) {
        return 0;
    }
    if (num >= 3) {
        for (T i = 3; (i * i) < (num); i = (i + 2)) {
            if ((num % i) == 0) {
                result = false;
                break;
            }
        }
    }
    return (result);
}

int main() {
    // perform self-test
    assert(is_prime(50) == false);
    assert(is_prime(115249) == true);

    int num;
    std::cout << "Enter the number to check if it is prime or not" << std::endl;
    std::cin >> num;
    bool result = is_prime(num);
    if (result) {
        std::cout << num << " is a prime number" << std::endl;
    } else {
        std::cout << num << " is not a prime number" << std::endl;
    }

    return 0;
}

