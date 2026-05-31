#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

mt19937 rng(random_device{}());

long long rand_int(long long l, long long r) {
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

string rand_string(int len) {

    string s;

    for (int i = 0; i < len; i++) {
        s += char(rand_int('a', 'z'));
    }

    return s;
}
void gen_int_test(int id) {

    int n;

    switch (id) {
    case 1: n = 100000; break; 
    case 2: n = 100000; break; 
    case 3: n = 5000;   break; 
    case 4: n = 100000; break; 
    case 5: n = 100000; break; 
    default: n = 100;
    }

    cout << n << '\n';

    vector<int> v(n);

    if (id == 1) {

        for (int i = 0; i < n; i++) {
            v[i] = i;
        }

        for (int i = 127; i < n; i += 128) {
            swap(v[i], v[i - 1]);
        }
    }

    else if (id == 2) {

        for (int i = 0; i < n; i++) {
            v[i] = rand_int(0, 31);
        }

        shuffle(v.begin(), v.end(), rng);
    }

    else if (id == 3) {

        for (int i = 0; i < n; i++) {

            int r = rand_int(1, 100);

            if (r <= 90) {

                v[i] = rand_int(0, 9);
            }
            else if (r <= 95) {

                v[i] = INT_MAX - rand_int(0, 1000);
            }
            else {

                v[i] = INT_MIN + rand_int(0, 1000);
            }
        }

        shuffle(v.begin(), v.end(), rng);
    }

    else if (id == 4) {

        for (int i = 0; i < n; i++) {
            v[i] = i / 64;
        }

        for (int i = 255; i < n; i += 256) {
            swap(v[i], v[i - 1]);
        }
    }

    else if (id == 5) {

        int upper = (123456 << 12);

        for (int i = 0; i < n; i++) {

            v[i] = upper | rand_int(0, 4095);
        }

        shuffle(v.begin(), v.end(), rng);
    }

    for (int x : v) {
        cout << x << ' ';
    }

    cout << '\n';
}
void gen_strlexi_test(int id) {

    int n=100000;

    cout << n << '\n';

    if (id == 1) {

        for (int i = 0; i < n; i++) {

            string s(95, 'a');

            int x = i;

            for (int j = 0; j < 5; j++) {
                s += char('a' + (x % 26));
                x /= 26;
            }

            cout << s << '\n';
        }
    }

    else if (id == 2) {



        for (int i = 0; i < n / 2; i++) {

            string s(95, 'a');

            int x = i;

            for (int j = 0; j < 5; j++) {
                s += char('a' + (x % 26));
                x /= 26;
            }

            cout << s << '\n';
        }

        for (int i = 0; i < n / 2; i++) {

            string s(95, 'b');

            int x = i;

            for (int j = 0; j < 5; j++) {
                s += char('a' + (x % 26));
                x /= 26;
            }

            cout << s << '\n';
        }
    }

    else if (id == 3) {

   

        for (int i = 0; i < n / 2; i++) {
            cout << string(100, 'a') << '\n';
        }

        for (int i = 0; i < n / 2; i++) {
            cout << string(100, 'b') << '\n';
        }
    }

    else if (id == 4) {


        for (int i = 0; i < n; i++) {

            string s(97, 'a');

            s += char('a' + (i % 26));
            s += char('a' + ((i / 26) % 26));
            s += char('a' + ((i / 676) % 26));

            cout << s << '\n';
        }
    }

    else if (id == 5) {

  

        for (int i = 0; i < n; i++) {

            int len = 10 + (i % 91);

            cout << string(len, 'a') << '\n';
        }
    }
}

void gen_strlenlexi_test(int id) {

    int n;

    switch (id) {
    case 1: n = 10000; break;  
    case 2: n = 10000; break;  
    case 3: n = 10000; break;  
    case 4: n = 10000; break; 
    case 5: n = 10000; break;   
    default: n = 10;
    }

    cout << n << '\n';



    if (id == 1) {

        int per_len = n / 91;
        int remain = n % 91;

        for (int len = 10; len <= 100; len++) {

            int cnt = per_len + (remain > 0);
            if (remain > 0) remain--;

            for (int k = 0; k < cnt; k++) {

                string s(len, 'a');

                int x = k;

                for (int pos = len - 1; pos >= 0 && x > 0; pos--) {
                    s[pos] = 'a' + (x % 26);
                    x /= 26;
                }

                cout << s << '\n';
            }
        }
}


    else if (id == 2) {
        string s = rand_string(50);
        for (int i = 0; i < n; i++) {
            cout << s << '\n';
        }
    }

   
    else if (id == 3) {
        string prefix(90, 'a');  
        for (int i = 0; i < n; i++) {
            int extra = rand_int(1, 10);  
            string s = prefix + rand_string(extra);
            cout << s << '\n';
        }
    }

    

    else if (id == 4) {

        vector<string> v;
        v.reserve(n);

        int per_len = n / 91;
        int remain = n % 91;

        for (int len = 10; len <= 100; len++) {

            int cnt = per_len + (remain > 0);
            if (remain > 0) remain--;

            for (int k = 0; k < cnt; k++) {

                string s(len, 'a');

                int x = k;

                for (int pos = len - 1; pos >= 0 && x > 0; pos--) {
                    s[pos] = 'a' + (x % 26);
                    x /= 26;
                }

                v.push_back(move(s));
            }
        }

        for (int i = 127; i < (int)v.size(); i += 128) {
            swap(v[i], v[i - 1]);
        }

        for (auto& s : v) {
            cout << s << '\n';
        }
    }
    else if (id == 5) {
        string prefix(8, 'a');
        for (int i = 0; i < n / 2; i++) {  
            cout << prefix + rand_string(2) << '\n';
        }
        for (int i = 0; i < n / 2; i++) {
            cout << prefix + rand_string(92) << '\n';
        }
    }
}

int main(int argc, char* argv[]) {

  
    if (argc != 3) {

        cerr << "Usage:\n";
        cerr << "test_gen <int/strlexi/strlenlexi> <1-5>\n";

        return 1;
    }

    string benchmark = argv[1];

    int test_id;

    try {
        test_id = stoi(argv[2]);
    }
    catch (...) {

        cerr << "Invalid test id\n";
        return 1;
    }

    if (test_id < 1 || test_id > 5) {

        cerr << "Test id must be from 1 to 5\n";
        return 1;
    }

   
    if (benchmark == "int") {

        gen_int_test(test_id);
    }
    else if (benchmark == "strlexi") {

        gen_strlexi_test(test_id);
    }
    else if (benchmark == "strlenlexi") {

        gen_strlenlexi_test(test_id);
    }
    else {

        cerr << "Unknown benchmark type\n";

        return 1;
    }

    return 0;
}