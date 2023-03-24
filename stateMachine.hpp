#pragma once
#include <memory>
#include <stack>
#include "state.hpp"

namespace Clovicorn
{
    typedef std::unique_ptr<State> stateRef;
    class StateMachine
    {
    public:
        StateMachine() {}
        ~StateMachine() {}

        void addState(stateRef newState, bool isReplacing = true);
        void removeState();
        void processStateChanges();

        stateRef &getActiveState();

    private:
        std::stack<stateRef> _states;
        stateRef _newState;

        bool _isReplacing;
        bool _isRemoving;
        bool _isAdding;
    };
}