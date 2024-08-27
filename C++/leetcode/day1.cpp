class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //strcmp(ransomNote,magazine);
	if(ransomNote.size()>magazine.size())
    {
        return false;
    }

    vector<int> cnt(26);

 for (auto & c : magazine) {    //for(auto c:s)中s为一个容器（数组或string），效果是利用c遍历并获得s容器中的每一个值，但是c无法影响到s容器中的元素。
                                //for(auto &c:s)中加了引用符号，可以对容器中的内容进行赋值，即可通过对c赋值来做到容器s的内容填充。
            cnt[c - 'a']++;
        }

    for(auto &c : ransomNote)
    {
        cnt[c -'a']--;
        if(cnt[c-'a'] < 0)
        {
            return false;
        }
    }
    return true;
    }
};