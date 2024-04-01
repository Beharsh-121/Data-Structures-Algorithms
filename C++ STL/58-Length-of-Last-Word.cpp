//T.C- O(n), S.C- O(1)  OMO
int lengthOfLastWord(string s) {
        int n = s.length(), count = 0;

        for(int i = n-1; i >= 0; i--){
          if(s[i] == ' ' and count == 0) continue;
          else if(s[i] == ' ' and count) break;
          else count++;
        }
        return count;
    }
//T.C- O(n), S.C- O(1)
int lengthOfLastWord(string s) {
        int idx = s.find_last_not_of(' ') + 1;
        s.erase(idx);
        int last_space_idx = s.find_last_of(' ');
        return last_space_idx == string::npos ? s.length() : s.length() - last_space_idx - 1;

    }