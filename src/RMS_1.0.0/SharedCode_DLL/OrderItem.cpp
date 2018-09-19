#include "OrderItem.h"

SharedCode::OrderItem::OrderItem()
{
   this->customizations = new vector<string*>;
}

SharedCode::OrderItem::OrderItem(Recipe * recipe)
{
   this->recipe = recipe; 
   this->customizations = new vector<string*>;
}

SharedCode::OrderItem::~OrderItem()
{
   for(
      vector<string*>::iterator iterator = this->customizations->begin(); 
      iterator != this->customizations->end(); 
      iterator++)
      delete *iterator;

   this->customizations->clear();
   delete this->customizations;
}

void SharedCode::OrderItem::AddCustomization(string * customization)
{
   if(customization != NULL)
      customizations->push_back(customization);
}

void SharedCode::OrderItem::RemoveCustomization(string * removable)
{
   if (removable != NULL)
   {
      int index = -1;
      for (int i = 0; i < customizations->size() && index == -1; i++)
      {
         if (*(*customizations)[i] == *removable)
            index = i;
      }
      if (index != -1)
         customizations->erase(customizations->begin() + (index));
   }
}

float SharedCode::OrderItem::GetPrice()
{
	return recipe->Price();
}

vector <string*> *  SharedCode::OrderItem::GetCustomizations()
{
	return this->customizations;
}

SharedCode::Recipe * SharedCode::OrderItem::GetRecipe()
{ 
   return recipe; 
}