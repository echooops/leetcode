#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string in;
    while (cin >> in) {
        string out;
        for (int i = 0; i < in.size(); i++) {
            string::size_type pos = out.find(in[i]);
            if (pos == string::npos)
                out += in[i];
            else {
                if (out[pos] < out[pos + 1]) {
                    out.erase(pos, 1);
                    out += in[i];
                }
            }
        }
        cout << out << "\n";
    }
    return 0;
}
