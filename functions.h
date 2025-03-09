double subtract(double a, double b){
    return (a - b);
}

double divide(double a, double b){
    return (a/b);
}

double biggest(double a, double b, double c){
    if (a >= b && a >= c){
        return a;
    }
    if (b >= a && b >= c){
        return b;
    }
    if (c >= a && c >= b){
        return c;
    }

    return 0;
}

double smallest(double a, double b, double c){
    if (a <= b && a <= c){
        return a;
    }
    if (b <= a && b <= c){
        return b;
    }
    if (c <= a && c <= b){
        return c;
    }
    return 0;
}

bool isOdd(int a){
    if (a % 2 != 0){
        return true;
    }

    return false;
}

bool isEven(int a){
    if (a % 2 == 0){
        return true;
    }

    return false;
}

int sumRange(int a, int b){
    int result = 0;
    for(int i = a; i <= b; i++){
        result += i;
    }
    return result;
}

int power(int a, int b){
    int result = a;
    for(int i = 1; i < b; i++){
        result *= a;
    }
    return result;
}

int randomNumber(int a, int b){
    int range = b - a;
    int result = rand() % range;
    result += a;
    return result;
}

bool isPrime(int a){
    if (a == 1) {
        return false;
    }
    for (int i = 2; i < a; i++){
        if (a % i == 0 && a != i){
            return false;
        }
    }
    return true;
}

void countPrimes(int a){
    std::cout << "The primes from 1 to " << a << " are: ";
    for(int i = 2; i <= a; i++){
        if (isPrime(i)){
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}