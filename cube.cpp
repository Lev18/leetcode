#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
/*
void back_track(std::vector<char>& perm, std::vector<char>& nums, 
                    std::vector<std::vector<char>>& ans, std::vector<char>& index) {
        if (nums.size() == perm.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
          if (i > 0 && nums[i] == nums[i - 1] && index[i - 1] == 1) continue;
          if (index[i] == 0) {
                perm.push_back(nums[i]);
                index [i] = 1;
                back_track(perm, nums, ans, index);
                perm.pop_back();
                index[i] = 0;
          }
        }
    }
    std::vector<std::vector<char>> permuteUnique(std::vector<char>& nums) {
      std::vector<std::vector<char>> ans;
      std::vector<char> perm;
      std::sort(nums.begin(), nums.end());
          
      std::vector<char> index (nums.size(),0);
        
      back_track(perm, nums, ans, index);
      
      return ans;
    }

std::string shift_str(const std::string& str, int shift_amount) {
    int len = str.size();
    std::string shifted_str = str;

    for (int i = 0; i < shift_amount; ++i) {
        char last_el = shifted_str[len - 1];
        for (int j = len; j >= 0; --j) {
            shifted_str[j] = shifted_str[j - 1];
        }
        shifted_str[0] = last_el;
    }
    return shifted_str;
}

void tocken_string(const std::string& val) {
    std::ofstream file("/home/levon/Workspace/leetcode/write.txt", std::fstream::trunc | std::fstream::out);
    if (!file.is_open()) {
        std::cout << "unable to open file" << std::endl;
    }
    std::string word;
    std::vector<char> tmp;
    int word_count{1};
    for (const auto& it_1 : val) {
      if (tmp.size() == 8) {
        std::vector<std::vector<char>> ans = permuteUnique(tmp);
        for (const auto& it_2 : ans) {
          for (const auto& it_3 : it_2) {
            word += it_3;
          }
          file << word <<'\n';
          word.clear(); 
        }
        ++word_count;
        file << word_count << '\n';
        tmp.clear();
      }
      
      tmp.push_back(it_1);
    }
    file.close();
}
*/

void decoder (std::string& str) {
  std::swap(str[7], str[1]);
  std::swap(str[6], str[0]);
  std::swap(str[5], str[3]);
  std::swap(str[4], str[2]);
}

int main() {
  std::string text = " syswaAlfoe ivtrllceexr n  iceenhiyterev dou ynginak To. tmetig rsdeuno he tndtamedaun fiss alntLe. ey k fngniarstmim roll aesakr fos ow athowgrromp ind. ntmevecoe  wAs oueinntrnou jurmere, eyo  termbur caystSu. usiocos esccomfrs mewod ar h dnd arkioaticedy nl On.hius pby lur ongcas itimis dwen our veco puetrr altienotr veNe. stredeunthe atimr wepoe el w aofedrmfol- Em.ea tha cryve igeenllpp oans tynituorarleo  texd ann n  Il.ceesqur ouknr fot e,dgleowndfie  wtr she ttoh gtenomrcve oacstobe tr Ss.lefog inivbee thr  swe, st sew netdsarndtaceexf  o. ceenllerthgeToan cwe, veiech akaarem rinthe blrdHa. gsals ipshe thg onkemay wach aur ontmeveie senevs . eretweday erEv c aisy toe nchacle ov mo  terosalgor ouieel Bs.yon  ive alfseurr ou yndy itilabe ak mtoerffdia Ea. ceenp te schd arrwfo ugsinbreroscls r ouo  ttirapiasta Ss.onoc fngyind aedusttmiom ccrs  iedfol iaucesccsur ouhr Ts.seer pghe,ncraveacree  whtigheh ev nwes ugho tersios ";
  std::string substr;
  std::string decoded_str;
  for (const auto it : text) {
    if (substr.size() == 8) {
      decoder(substr);
      decoded_str += substr;
      substr.clear();
    }
    substr += it;
  }
  std::ofstream file("/home/levon/Workspace/leetcode/write.txt", std::fstream::trunc | std::fstream::out);
    if (!file.is_open()) {
        std::cout << "unable to open file" << std::endl;
    }
file << decoded_str;
  //  std::vector<int> v = {1,2,2,4,4,6,5,4,2,1};

  //  auto ptr = std::unique(v.begin(),v.end());
  //  std::vector<int>::iterator it = v.begin();

  //  while (it != ptr) {
  //   std::cout << *it << std::endl;
  //   ++it;  
  // }
}



