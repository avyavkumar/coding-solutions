#include <bits/stdc++.h>

using namespace std;

typedef struct _node
{
  struct _node *parent;
  vector <struct _node *> child;
  string value;
  int times;
  int visited;
  _node() { parent = NULL; times = 0; visited = 0; value = "";}
} node;

class Solution
{
public:

    string decodeString(string s)
    {
      long long int pointer = 0;
      node *origin;
      node *root = new node();
      origin = root;
      while(pointer < s.size())
      {
        if (s.at(pointer) <= '9' && s.at(pointer) > '0')
        {
          long long int num = 0;
          while (s[pointer] <= '9' && s[pointer] >= '0')
          {
            if (num == 0)
              num = s[pointer] - '0';
            else
              num = num*10 + (s[pointer] - '0');
            pointer++;
          }
          pointer++;
          node *next = new node();
          next->parent = root;
          root->child.push_back(next);
          next->times = num;
          while ((s[pointer] >= 'a') && (s[pointer] <= 'z'))
          {
            next->value+=s[pointer];
            pointer++;
          }
          root = next;
        }
        else if ((s[pointer] >= 'a') && (s[pointer] <= 'z'))
        {
          node *next = new node();
          next->parent = root;
          root->child.push_back(next);
          next->times = 1;
          while ((s[pointer] >= 'a') && (s[pointer] <= 'z'))
          {
            next->value+=s[pointer];
            pointer++;
          }
        }
        else if (s[pointer] == ']')
        {
          root = root->parent;
          pointer++;
        }
      }
      string result = getString(origin);
      return result;
    }

    string getString(node *origin)
    {
      if (origin->visited == 0)
      {
        origin->visited = 1;
        string temp = "";
        if (origin->child.size() == 0 && origin->parent != NULL)
        {
          temp=origin->value;
          for (int i = 1; i < origin->times; i++)
            temp+=origin->value;
          return temp;
        }

        for (int i = 0; i < origin->child.size(); i++)
        {
          string x = getString(origin->child[i]);
          temp+=x;
        }

        if (origin->parent != NULL)
        {
          if (origin->value.size() > 0)
          {
            temp=origin->value + temp;
            string result;
            for (int i = 0; i < origin->times; i++)
              result+=temp;
            return result;
          }
          else if (origin->times > 0)
          {
            string result;
            for (int i = 0; i < origin->times; i++)
              result+=temp;
            return result;
          }
          else
            return temp;
        }
        else
          return temp;
      }
      else
        return "";
    }
};
