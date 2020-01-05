#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <string>
#include <wx/bitmap.h>

// forward declarations
class GraphNode;
class ChatLogic; 

/**
 * ChatBot class
 *
 * Includes unique pointer and implements the rule of five and move semantics
 * Look for numbering 1...5 in the code bellow for rule of 5 implementation
 * Reference: https://en.cppreference.com/w/cpp/language/rule_of_three
 */
class ChatBot {
private:
  // data handles (owned)
  wxBitmap *_image; // avatar image that is allocated on the heap

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
  // constructors / destructors
  ChatBot(); // constructor WITHOUT memory allocation
  ChatBot(std::string filename); // constructor WITH memory allocation

  // Rule of 5

  // 1. destructor
  ~ChatBot();

  // 2. copy constructor
  ChatBot(const ChatBot &);

  // 3. move constructor
  ChatBot(ChatBot &&);

  // 4. copy assignment operator
  ChatBot &operator=(const ChatBot &);

  // 5. Move assignment operator
  ChatBot &operator=(ChatBot &&);

  // getters / setters
  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  wxBitmap *GetImageHandle() { return _image; }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */