#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <string>
#include <wx/bitmap.h>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

/**
 * ChatBot class 
 * 
 * Includes unique pointer and implements the rule of five
 * Look for numbering 1...5 in the code bellow for rule of 5 implementation
 * Reference: https://en.cppreference.com/w/cpp/language/rule_of_three
 */
class ChatBot {
private:
  // data handles (owned)
  wxBitmap *_image; // avatar image

  // data handles (not owned)
  GraphNode *_currentNode;
  GraphNode *_rootNode;
  ChatLogic *_chatLogic;

  // proprietary functions
  int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
  // constructors / destructors
  ChatBot();                     // constructor WITHOUT memory allocation
  ChatBot(std::string filename); // constructor WITH memory allocation

  // 1. Destructor
  ~ChatBot();         

  //// STUDENT CODE
  ////           

  // 2. Copy constructor
  ChatBot(const ChatBot&);

  // 3. Move constructor
  ChatBot(ChatBot&&);

  // 4. Copy assignment operator
  ChatBot& operator=(const ChatBot&);

  // 5. Move assignment operator
  ChatBot& operator=(ChatBot&&);

  ////
  //// EOF STUDENT CODE

  // getters / setters
  void SetCurrentNode(GraphNode *node);
  void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
  void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
  wxBitmap *GetImageHandle() { return _image; }

  // communication
  void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */