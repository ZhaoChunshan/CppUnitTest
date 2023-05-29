//
// Created by mst on 5/28/23.
//
#include <bits/stdc++.h>
using namespace std;

fstream fout_sort;
fstream fout_hash;
fstream fout_feb;
fstream fout_matrix;
fstream fout_reserve;
fstream fout_binary;

fstream fans_sort;
fstream fans_hash;
fstream fans_feb;
fstream fans_matrix;
fstream fans_reserve;
fstream fans_binary;

void Open(string file_name, fstream &In, fstream &Ans) {
    string input_file = file_name + ".in";
    string ans_file = file_name + ".ans";
    system(("touch " + input_file).c_str());
    system(("touch " + ans_file).c_str());

    In = fstream(input_file.c_str(), ios::out);
    Ans = fstream(ans_file.c_str(), ios::out);
}


void data_gen_sort(string file_name, int n, int m) {
    Open(file_name, fout_sort, fans_sort);
    int *a = new int[1000100];

    fout_sort << n << "\n";
    for(int i=1;i<=n;i++) {
        fout_sort << (a[i] = rand()%m) << "\n";
    }

    cout << file_name << ".in gen complete!\n";

    sort(a+1, a+1+n);
    fans_sort << n << "\n";
    for(int i=1;i<=n;i++) {
        fans_sort << a[i] << "\n";
    }

    cout << file_name << ".ans gen complete!\n";
    delete a;
}

void data_gen_hash(string file_name, int n, int m) {
    Open(file_name, fout_hash, fans_hash);
    map<int,int> mm;
    fout_hash << n << " " << m << "\n";
    int *x = new int[1000010], *y = new int[1000010];
    for(int i=1;i<=n;i++) {
        x[i] = n*10000 + rand()%1000000;
        y[i] = rand()%10000;
        fout_hash << x[i] << " " << y[i] << "\n";
        auto it = mm.find(x[i]);
        if(it != mm.end()){
            it->second = y[i];
        } else{
            mm[x[i]] = y[i];
        }
    }

    for(int i=1;i<=m;i++) {
        int t;
        if(rand()%10 <= 9){
            fout_hash << x[(t = (rand()%n + 1))] << endl,
                    fans_hash << mm.at(x[t]) << endl;
        }

        else
            fout_hash << rand()%9999 << endl,
                    fans_hash << -1 << endl;
    }
    cout << file_name << ".in gen complete!\n";
    cout << file_name << ".ans gen complete!\n";
    delete x;
    delete y;
}

long long f[1000010];
long long a[1100][1100],b[1100][1100],c[1100][1100];
void data_gen_feb(string file_name, int n, int m) {
    Open(file_name, fout_feb, fans_feb);

    fout_feb << n << "\n";
    cout << file_name << ".in gen complete!\n";

    f[0] = 0;
    f[1] = 1;

    for(int i=2;i<=n;i++) {
        f[i] = f[i-1]+f[i-2];
    }

    fans_feb << f[n];
    cout << file_name << ".ans gen complete!\n";
}

void data_gen_matrix(string file_name, int n, int m) {
    Open(file_name, fout_matrix, fans_matrix);

    fout_matrix << n << "\n";
    for(int i=0;i<n;i++, fout_matrix << endl)
        for (int j = 0; j < n; j++)
            fout_matrix << (a[i][j] = rand() % m) << " ";
    fout_matrix << endl;

    for(int i=0;i<n;i++, fout_matrix << endl) {
        for (int j = 0; j < n; j++)
            fout_matrix << (b[i][j] = rand() % m) << " ";
    }
    fout_matrix << endl;
    cout << file_name << ".in gen complete!\n";

    for(int i=0;i<n;i++,fans_matrix << endl)
        for(int j=0;j<n;j++) {
            c[i][j]=0;
            for(int k=0;k<n;k++) {
                c[i][j]+=a[i][k]*b[k][j];
            }
            fans_matrix << c[i][j] << " ";
        }


    cout << file_name << ".ans gen complete!\n";
}

void data_gen_reserve(string file_name, int n, int m) {
    Open(file_name, fout_reserve, fans_reserve);

    fout_reserve << n << "\n";
    for(int i=0;i<n;i++)
        fout_reserve << (f[i] = rand()%m) << endl;
    cout << file_name << ".in gen complete!\n";

    for(int i=n-1;i>=0;i--) {
        fans_reserve << f[i] << endl;
    }
    cout << file_name << ".ans gen complete!\n";
}

void data_gen_binary(string file_name, int n, int m) {
    Open(file_name, fout_binary, fans_binary);

    int *a = new int [1000010];
    fout_binary << n << "\n";
    for(int i=1;i<=n;i++) {
        fout_binary << (a[i] = rand()%m) << "\n";
    }

    cout << file_name << ".in gen complete!\n";

    sort(a+1, a+1+n);
    fans_binary << n << "\n";
    for(int i=1;i<=n;i++) {
        fans_binary << a[i] << "\n";
    }

    cout << file_name << ".ans gen complete!\n";
    delete a;
}

void data_gen(string alg_name, void (*fun)(string, int, int)) {
    cout << "input " << alg_name << " data number : ";
    int t;
    cin >> t;
    int n, m;
    cout << "input " << "size n with domain m : ";
    cin >> n >> m;
    for(int i=1;i<=t;i++) {
        string str = alg_name + to_string(i);
        fun(str, n, m);
    }
}
int main()
{
//    create_file();
    data_gen("sort", data_gen_sort);
    data_gen("hash", data_gen_hash);
    data_gen("feb", data_gen_feb);
    data_gen("matrix", data_gen_matrix);
    data_gen("reserve", data_gen_reserve);
    data_gen("binary", data_gen_binary);
}
