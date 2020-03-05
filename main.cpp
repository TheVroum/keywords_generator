#include <QApplication>
#include <QInputDialog>
#include <vector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString ret = QInputDialog::getMultiLineText(nullptr, "Mot clés"
        , "Saississez ci-dessous les mots à traiter.", "Saississez l'entrée ici.");
    QStringList two = ret.split("|");
    QStringList binaries = two[1].split(":");
    std::vector <QStringList> field;
    for(auto a : two[0].split(":"))
        field.push_back(a.split(","));

    QStringList origin;
    QStringList target;
    origin.push_back("");

    for(auto a : field)
    {
        target.clear();
        for(auto &b : origin)
            for(auto c : a)
                target.push_back(b + " " + c);
        origin.swap(target);
    }


    for(auto a : binaries)
    {
        target.clear();
        for(auto b : origin)
            target.push_back(b), target.push_back(b + a);
        origin.swap(origin);
    }

    QInputDialog::getMultiLineText(nullptr, "Mot clés traités"
        , "Vous pouvez ci-dessous récupérer les mots traités.", origin.join(",\n"));





    for(auto &a : field)
        a.push_back("");
    origin.clear();
    target.clear();
    origin.push_back("");

    for(auto a : field)
    {
        target.clear();
        for(auto &b : origin)
            for(auto c : a)
                target.push_back(b + " " + c);
        origin.swap(target);
    }


    for(auto a : binaries)
    {
        target.clear();
        for(auto b : origin)
            target.push_back(b), target.push_back(b + a);
        origin.swap(origin);
    }

    QInputDialog::getMultiLineText(nullptr, "Mot clés traités"
        , "Vous pouvez ci-dessous récupérer les mots traités.", origin.join(",\n"));
    return a.exec();
}
