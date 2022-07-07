#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class WordInfo
{
public:
  string m_word;
  int m_weight;

  WordInfo()
    :m_word("")
    , m_weight(0) {
  }

  WordInfo(string word, int weight)
    :m_word(word)
    , m_weight(weight) {
  }
};

auto cmpi = [](WordInfo& a, WordInfo& b) {return a.m_weight < b.m_weight;};
auto cmpd = [](WordInfo& a, WordInfo& b) {return a.m_weight > b.m_weight;};

class Node
{
public:
  vector<WordInfo> m_wordInfos;
  vector<shared_ptr<Node>> m_children;

  Node() :
    m_wordInfos(vector<WordInfo>())
    , m_children(26, shared_ptr<Node>()) {
  }

};

using NodePtr = shared_ptr<Node>;
class Trie
{
private:
  NodePtr m_root;
public:
  Trie() :m_root(make_shared<Node>()) {
  }
  void buildTrie(const vector<WordInfo>&);
  vector<string> searchPrefix(const string&);
};


void Trie::buildTrie(const vector<WordInfo>& wordInfos) {
  NodePtr root = m_root;
  for (auto j = 0; j < wordInfos.size(); j++) {
    string word = wordInfos[j].m_word;
    root = m_root;
    for (auto i = 0; i < word.length(); i++) {
      if (root->m_children[word[i] - 'a'] == nullptr) {
        root->m_children[word[i] - 'a'] = make_shared<Node>();
      }
      root = root->m_children[word[i] - 'a'];

      //on child Node store curr word.
      // we need max 5 words max
      if (root->m_wordInfos.size() < 5) {
        root->m_wordInfos.push_back(words[j]);
      }
      else {
        //if we already have 5 words and curr word is weight more than remove one
        // word from vector and add new one. Than again sort the vector. TC. 5log(5)
        if (root->m_wordInfos[0].m_weight < wordInfos[j].m_weight) {
          root->m_wordInfos[0] = wordInfos[j];
        }
      }
      sort(root->m_wordInfos.begin(), root->m_wordInfos.end(), cmpi);
    }
  }
  return;
}

vector<string> Trie::searchPrefix(const string& prefix) {
  vector<string> res;
  NodePtr root = m_root;
  for (auto ch : prefix) {
    if (root->m_children[ch - 'a'] == nullptr) {
      res.push_back(string("-1"));
      return res;
    }
    root = root->m_children[ch - 'a'];
  }
  for (int i = root->m_wordInfos.size() - 1; i >= 0; i--) {
    res.push_back(root->m_wordInfos[i].m_word);
  }

  return res;
}

int main() {
  int testNum;
  cin >> testNum;
  while (testNum--) {
    int N, M;
    cin >> N >> M;
    vector<WordInfo> wordInfos(N);
    for (auto i = 0; i < N; i++)
      cin >> wordInfos[i].m_word;

    for (auto i = 0; i < N; i++)
      cin >> wordInfos[i].m_weight;

    vector<string> prefixs(M);
    for (auto i = 0; i < M; i++)
      cin >> prefixs[i];

    sort(wordInfos.begin(), wordInfos.end(), cmpd); //first sort words in decreaseing weight
    Trie trie;
    trie.buildTrie(wordInfos);

    for (auto prefix : prefixs) {
      auto resList = trie.searchPrefix(prefix);
      for (auto res : resList) {
        cout << res << ' ';
      }
      cout << endl;
    }

  }

  return 0;
}