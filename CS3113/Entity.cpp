#include "Entity.h"

Entity::Entity() : mBody { 0.0f, 0.0f, 0.0f, 0.0f }, mPosition { 0.0f, 0.0f }, mMovement { 0.0f, 0.0f } {}

Entity::Entity(Rectangle body, Vector2 position) : mBody {body}, mPosition {position}, mMovement { 0.0f, 0.0f } {}

Entity::Entity(int screenWidth, int screenHeight) : mMovement { 0.0f, 0.0f }
{
    mBody = {
        screenWidth  / 2.0f,
        screenHeight / 2.0f,
        DEFAULT_SIZE,
        DEFAULT_SIZE
    };

    mPosition = { screenWidth / 2.0f, screenHeight / 2.0f };
}

Entity::~Entity() {};

void Entity::frameReset()
{
    mBody.x = 0;
    mBody.y = 0;
    mBody.width = DEFAULT_SIZE;
    mBody.height = DEFAULT_SIZE;
}

void Entity::update()
{
    frameReset();

    mPosition.x += mMovement.x * 2;
    mPosition.y += mMovement.y * 2;

    mBody.x = mPosition.x; 
    mBody.y = mPosition.y;
}