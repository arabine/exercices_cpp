#include <iostream>
#include <string>

class Book
{

public:
    Book(const std::string &title, const std::string &author, int pages) {
        mTitle = title;
        mAuthor = author;
        mPages = pages;
    }

    Book() {
        mPages = 0;
        mTitle = "non defini";
        mAuthor = "non defini";
    }

    void display() {
        std::cout << "---------------------------------------\n"
                  << "Title: " << mTitle << "\n"
                  << "Auhtor: " << mAuthor << "\n"
                  << "Pages: " << mPages << "\n";
    }

    int GetPages() const { return mPages; }
    std::string GetTitle() const { return mTitle; }
    std::string GetAuthor() const { return mAuthor; }

protected:
    std::string mTitle;
    std::string mAuthor;
    int mPages;
};


class Novel : public Book
{
public:
    Novel(const std::string &title, const std::string &author, int pages, bool g)
        : Book(title, author, pages)
    {
        mGoncourt = g;
    }

    Novel() : Book() {
        mGoncourt = false;
    }

    void display() {
        Book::display();
        std::cout << "Goncourt: " << mGoncourt << "\n"
                   << "Price: " << computePrice() << std::endl;
    }

    double computePrice() {
        if (mGoncourt)
        {
            return 0.05 * mPages;
        }
        else
        {
            return 0.01 * mPages;
        }
    }

private:
    bool mGoncourt;
};

class Comic  : public Book
{
public:
    Comic(const std::string &title, const std::string &author, int pages, const std::string &cartoonist)
        : Book(title, author, pages)
    {
        mCartoonist = cartoonist;
    }

    void display() {
        Book::display();
        std::cout << "Cartoonist: " << mCartoonist << "\n"
                     << "Price: " << computePrice() << std::endl;
    }

    double computePrice() {
        return 0.30 * mPages;
    }


private:
    std::string mCartoonist;

};


class GraphicNovel : public Comic, public Novel
{
public:
    GraphicNovel(const std::string &title, const std::string &author, const std::string &cartoonist, int pages, bool approved)
       :  Comic(title, author, pages, cartoonist)
       , Novel(title, author, pages, false)

    {
        mInrocksApproved = approved;
    }

    void display() {
        std::cout << "---------------------------------------\n"
                  << "Title: " << Comic::GetTitle() << "\n"
                  << "Author: " << Comic::GetAuthor() << "\n"
                  << "Pages: " << Comic::GetPages() << "\n";
        // and that of a Graphic Novel is 0.20€ per page.
        std::cout << "Price: " <<  computePrice() << "\n";
        std::cout << "Inrocks Approved: " << mInrocksApproved << "\n" << std::endl;
    }

    double computePrice() {
        return 0.20 * Comic::GetPages();
    }

private:
    bool mInrocksApproved = false;

};


int main()
{
    Novel fondation("Fondation", "Asimov", 434, false);
    Novel scorta("Le Soleil des Scorta", "Laurent Gaudé", 628, true);
    Comic boulet("La Rubrique sceintifique", "Boulet", 42, "Boulet");

    GraphicNovel persepolis("Persepolis", "Marjane Satrapi", "Marjane Satrapi", 324, true);

    fondation.display();
    scorta.display();
    boulet.display();
    persepolis.display();

    return 0;
}

