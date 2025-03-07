float subtract(float a, float b){
    return (a - b);
}

float divide(float a, float b){
    return (a/b);
}

float biggest(float a, float b, float c){
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

float smallest(float a, float b, float c){
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
    srand(time(0));
    int range = b - a;
    int result = rand() % range;
    result += a;
    return result;
}

bool isPrime(int a){
    
}