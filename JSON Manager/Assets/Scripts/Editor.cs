using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;

public class Editor : EditorWindow
{
    // Use this for initialization

    //Create menu option
    [MenuItem("Import/Import Scene")]
    static void Init()
    {
        //Locate array script for holding all objects.
        ArrayScript ArrayScript;
        string path = EditorUtility.OpenFilePanel("Import new scene", Application.dataPath, "");
        if (File.Exists(path))
        {
            string jsonstring = File.ReadAllText(path);
            //ItemArray 
            //Debug.Log(jsonstring);
            ArrayScript = JsonUtility.FromJson<ArrayScript>(jsonstring);
            //Search through the .json file and read values.
            foreach (var Item in ArrayScript.Item)
            {
                //Create new game objects using provided json values.
                GameObject gameObject = new GameObject(Item.itemType);
                gameObject.transform.position = new Vector3(Item.Posx, Item.Posy, Item.Posz);
                gameObject.transform.rotation = Quaternion.Euler(Item.Rotx, Item.Roty, Item.Rotz);
                gameObject.transform.localScale = new Vector3(Item.Scalex, Item.Scaley, Item.Scalez);
                //Check if rigidbody is needed.
                if (Item.Rigidbody == true)
                {
                    gameObject.AddComponent<Rigidbody>();
                }
                // Use mesh filter?
                if (Item.MeshFilter == true)
                {
                    gameObject.AddComponent<MeshFilter>();
                    Vector3[] vertices = new Vector3[Item.numVerts];
                    int i = 0;
                    for (int x = 0; x < 8; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (y == 0)
                            { vertices[x].x = Item.Verts[i]; }
                            if (y == 1)
                            { vertices[x].y = Item.Verts[i]; }
                            if (y == 2)
                            { vertices[x].z = Item.Verts[i]; }
                            //Debug.Log(Item.Verts[i] + " " + i);
                            i++;
                        }
                    }
                    gameObject.GetComponent<MeshFilter>().mesh.Clear();
                    gameObject.GetComponent<MeshFilter>().mesh.vertices = vertices;
                    gameObject.GetComponent<MeshFilter>().mesh.triangles = Item.triangles;
                    gameObject.GetComponent<MeshFilter>().mesh.RecalculateNormals();
                }
                //Add Box collider
                if (Item.BoxCollider == true)
                {
                    gameObject.AddComponent<BoxCollider>();
                }
                // Mesh render if true
                if (Item.MeshRenderer == true)
                {
                    gameObject.AddComponent<MeshRenderer>();
                    gameObject.GetComponent<MeshRenderer>().material = AssetDatabase.GetBuiltinExtraResource<Material>("Default-Diffuse.mat");
                }
				gameObject.GetComponent<BoxCollider> ().center = new Vector3 (Item.centerx, Item.centery, Item.centerz);
                gameObject.GetComponent<MeshRenderer>().material = AssetDatabase.GetBuiltinExtraResource<Material>("Default-Diffuse.mat");
            }
        }
    }
}