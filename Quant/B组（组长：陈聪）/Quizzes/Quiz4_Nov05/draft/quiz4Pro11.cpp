string reverse(string &str) {
    int n = str.length();
    if (n < 2) return str;
    int i = 0;
    int j = n-1;
    while (i < j) {
         swap(str[i],str[j]);
         i++;
         j++;
    }
}


bool checkPalingdrome(string str) {
    string str1 = str;
    reverse(str);
    for (int i =0; i < str.length(); ++i) {
        if (str1[i] != str[i]) return 0;
    }
    return 1;
}