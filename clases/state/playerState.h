//
// Created by ribetti on 25/6/2020.
//

#ifndef SQUARECRAFT_PLAYERSTATE_H
#define SQUARECRAFT_PLAYERSTATE_H

#include <iostream>
#include <typeinfo>
#include "../Player/Player.h"
Player &playerr = Player::getInstance();

/**
 * State Design Pattern
 *
 * Intent: Lets an object alter its behavior when its internal state changes. It
 * appears as if the object changed its class.
 */

/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the Context object, associated
 * with the State. This backreference can be used by States to transition the
 * Context to another State.
 */

class Context;

class State {
    /**
     * @var Context
     */
protected:
    Context *context_;

public:
    virtual ~State() {
    }

    void set_context(Context *context) {
        this->context_ = context;
    }

    virtual void left() = 0;
    virtual void right() = 0;
    virtual void up() = 0;
    virtual void down() = 0;
    virtual void change() = 0;
    //virtual void mine() = 0;
};

/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */
class Context {
    /**
     * @var State A reference to the current state of the Context.
     */
private:
    State *state_;

public:
    Context(State *state) : state_(nullptr) {
        this->TransitionTo(state);
    }
    ~Context() {
        delete state_;
    }
    /**
     * The Context allows changing the State object at runtime.
     */
    void TransitionTo(State *state) {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_context(this);
    }
    /**
     * The Context delegates part of its behavior to the current State object.
     */
    void left(){
        this->state_->left();
    }
    void right(){
        this->state_->right();
    }
    void up(){
        this->state_->up();
    }
    void down(){
        this->state_->down();
    }
    void change(){
        this->state_->change();
    }
};

/**
 * Concrete States implement various behaviors, associated with a state of the
 * Context.
 */

class walking : public State {
public:
    void left() override{
        playerr.updatePosition('l');
    }
    void right() override {
        playerr.updatePosition('r');
    }
    void up() override; //cambio al estado jumping
    void down() override{
        //playerr.updatePosition('d');
    }
    void change() override {}; //no hace nada
};

class jumping : public State {
private:
    int high{0};
public:
    void left() override {
        playerr.updatePosition('l');
    }
    void right() override {
        playerr.updatePosition('r');
    }
    void up() override{
        playerr.updatePosition('u');
    }
    void down() override;
    void change() override;
};

void walking::up() {
    {
        std::cout << "lets jump \n";
        this->context_->TransitionTo(new jumping);
    }
}

class falling : public State {
public:
    void left() override {
        playerr.updatePosition('l');
    }
    void right() override {
        playerr.updatePosition('r');
    }

    void up() override{ //no hace nada

    }
    void down() override {
        //speeds up the fall
        playerr.updatePosition('d');
    }
    void change() override {
        std::cout << "ahora a caminar se dijo \n";
        this->context_->TransitionTo(new walking);
    };
};

void jumping::change() {
    std::cout << "me caigo we \n";
    this->context_->TransitionTo(new falling);
}
void jumping::down() {

    if (high < 32 && playerr.up){
        playerr.updatePosition('u');
        high++;
    } else {
        high = 0;
        std::cout << "me caigo we \n";
        this->context_->TransitionTo(new falling);
    }
}

#endif //SQUARECRAFT_PLAYERSTATE_H