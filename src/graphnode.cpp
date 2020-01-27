#include "graphedge.h"
#include "graphnode.h"
#include <memory>
#include <utility>
#include <iostream>

GraphNode::GraphNode(int id) 
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

//// ADDITIONAL STUDENT CODE
////
void GraphNode::AddEdgeToParentNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.emplace_back(std::move(edge));
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}
////
//// EOF ADDITIONAL STUDENT CODE

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////
    return _childEdges[index].get();
    ////
    //// EOF STUDENT CODE
}
