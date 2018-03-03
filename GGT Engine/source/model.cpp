#include "model.h"

Model::Model(std::string fileName)
{
    LoadModel(fileName);
}

void Model::LoadModel(std::string fileName)
{
    std::vector<sf::Vector3f> positions;
    std::vector<sf::Vector2f> texcoords;
    std::vector<sf::Vector3f> normals;
    std::vector<FaceData> temp_faces;

    std::ifstream fileStream;
    fileStream.open(fileName.c_str());

    if (!fileStream.is_open())
    {
        std::cout << "Failed to load mesh: " << fileName << std::endl;
		return;
    }

    std::string lineStream;
    while (std::getline(fileStream, lineStream))
    {
        std::stringstream str_stream(lineStream);
        std::string type_str;
        str_stream >> type_str;

        if (type_str == "v")
        {
            sf::Vector3f position;
            str_stream >> position.x >> position.y >> position.z;
            positions.push_back(position);
        }
        else if (type_str == "vt")
        {
            sf::Vector2f texture;
            str_stream >> texture.x >> texture.y;
            texcoords.push_back(texture);
        }
        else if (type_str == "vn")
        {
            sf::Vector3f normal;
            str_stream >> normal.x >> normal.y >> normal.z;
            normals.push_back(normal);
        }
        else if (type_str == "f")
        {
            char temp;
            FaceData faceData;
            unsigned int v1, v2, v3;
            for (int i = 0; i < 3; ++i)
            {
                str_stream >> v1 >> temp >> v2 >> temp >> v3;
                faceData.vertexPositionsIndex.push_back(v1 - 1);
                faceData.vertexTexcoordsIndex.push_back(v2 - 1);
                faceData.vertexNormalsIndex.push_back(v3 - 1);
            }
            temp_faces.push_back(faceData);
        }
    }

    fileStream.close();

    for (uint16_t i = 0; i < temp_faces.size(); i++)
    {
        FaceData faceData = temp_faces[i];
        Face* newFace = new Face();

        for (int j = 0; j < 3; j++)
        {
            if (positions.size() > 0)
            {
                newFace->vertexPositions.push_back(positions[faceData.vertexPositionsIndex[j]]);
            }

            if (normals.size() > 0)
            {
                newFace->vertexNormals.push_back(normals[faceData.vertexNormalsIndex[j]]);
            }

            if (texcoords.size() > 0)
            {
                newFace->vertexTexcoords.push_back(texcoords[faceData.vertexTexcoordsIndex[j]]);
            }       
        }

        faces.push_back(newFace);
    }

    std::cout << "Loaded mesh: " << fileName << std::endl;;
}
