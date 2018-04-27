using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;

public class Editor : EditorWindow
{
    // Use this for initialization
    [MenuItem("Import/Import Scene")]
    static void Init()
    {
        ArrayScript ArrayScript;
        string path = EditorUtility.OpenFilePanel("Overwrite with Json", Application.dataPath, "");
        if (File.Exists(path))
        {
            string jsonstring = File.ReadAllText(path);
            //ItemArray 
            Debug.Log(jsonstring);
            ArrayScript = JsonUtility.FromJson<ArrayScript>(jsonstring);
            foreach (var Item in ArrayScript.Item)
            {
                GameObject gameObject = new GameObject(Item.itemType);
                gameObject.transform.position = new Vector3(Item.Posx, Item.Posy, Item.Posz);
                gameObject.transform.rotation = Quaternion.Euler(Item.Rotx, Item.Roty, Item.Rotz);
                gameObject.transform.localScale = new Vector3(Item.Scalex, Item.Scaley, Item.Scalez);
                if (Item.Rigidbody == true)
                {
                    gameObject.AddComponent<Rigidbody>();
                }
                if (Item.MeshFilter == true)
                {
                    gameObject.AddComponent<MeshFilter>();
                    Debug.Log("AX");
                    Vector3[] vertices = new Vector3[Item.numVerts];
                    int z = 0;
                    for (int x = 0; x < 8; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (y == 0)
                            { vertices[x].x = Item.Verts[z]; }
                            if (y == 1)
                            { vertices[x].y = Item.Verts[z]; }
                            if (y == 2)
                            { vertices[x].z = Item.Verts[z]; }
                            Debug.Log(Item.Verts[z] + " " + z);
                            z++;
                        }
                    }
                    gameObject.GetComponent<MeshFilter>().mesh.Clear();
                    gameObject.GetComponent<MeshFilter>().mesh.vertices = vertices;
                    gameObject.GetComponent<MeshFilter>().mesh.triangles = Item.triangles;
                    gameObject.GetComponent<MeshFilter>().mesh.RecalculateNormals();
                }
                if (Item.BoxCollider == true)
                {
                    gameObject.AddComponent<BoxCollider>();
                }
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