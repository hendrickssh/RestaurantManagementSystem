#pragma once

#include "stdafx.h"

#include "Recipe.h"

SharedCode::Recipe::Recipe()
{
	this->name = new string();
	this->price = 0.00f;
	this->description = new string();
}

SharedCode::Recipe::Recipe(string recipeName) : Recipe(new string(recipeName)) 
{

}

SharedCode::Recipe::Recipe(string * recipeName) : Recipe(recipeName, 0.00f, new string())
{

}

SharedCode::Recipe::Recipe(string * recipeName, float price, string * description)
{
	this->name = recipeName;
	this->price = price;
	this->description = description;
}

SharedCode::Recipe::~Recipe()
{
   delete this->name;
   delete this->description;
}

bool SharedCode::Recipe::operator==(Recipe * skeletonRecipe)
{
	return (name->compare(*skeletonRecipe->name)) == 0;
}

bool SharedCode::Recipe::operator==(const Recipe & skeletonRecipe)
{
	return (name->compare(*(&skeletonRecipe)->name)) == 0;
}

string * SharedCode::Recipe::Name()
{
   return this->name;
}

void SharedCode::Recipe::Name(string * newName)
{
	delete this->name;

	this->name = newName;
}

string * SharedCode::Recipe::Description()
{
	return this->description;
}

void SharedCode::Recipe::Description(string * newDescription)
{
	delete this->description;

	this->description = newDescription;
}

float SharedCode::Recipe::Price()
{
	return this->price;
}

void SharedCode::Recipe::Price(float newPrice)
{
	this->price = newPrice;
}

