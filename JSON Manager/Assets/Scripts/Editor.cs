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
            //sceneItemArray 
            Debug.Log(jsonstring);
            ArrayScript = JsonUtility.FromJson<ArrayScript>(jsonstring);

            foreach (var sceneItem in ArrayScript.Item)
            {

                GameObject gameObject = new GameObject(sceneItem.itemType);
                gameObject.transform.position = new Vector3(sceneItem.VecLocx, sceneItem.VecLocy, sceneItem.VecLocz);
                gameObject.transform.rotation = Quaternion.Euler(sceneItem.VecRotX, sceneItem.VecRotY, sceneItem.VecRotZ);
                gameObject.transform.localScale = new Vector3(sceneItem.VecSclX, sceneItem.VecSclY, sceneItem.VecSclZ);
                if (sceneItem.Rigidbody == true)
                {
                    gameObject.AddComponent<Rigidbody>();
                }
                if (sceneItem.MeshFilter == true)
                {
                    gameObject.AddComponent<MeshFilter>();
                    Debug.Log("AX");
                    Vector3[] vertices = new Vector3[sceneItem.numVerts];

                    int z = 0;
                    for (int x = 0; x < 8; x++)
                    {
                        for (int y = 0; y < 3; y++)
                        {
                            if (y == 0)
                            { vertices[x].x = sceneItem.Verts[z]; }
                            if (y == 1)
                            { vertices[x].y = sceneItem.Verts[z]; }
                            if (y == 2)
                            { vertices[x].z = sceneItem.Verts[z]; }
                            Debug.Log(sceneItem.Verts[z] + " " + z);
                            z++;
                        }
                    }
                    gameObject.GetComponent<MeshFilter>().mesh.Clear();
                    gameObject.GetComponent<MeshFilter>().mesh.vertices = vertices;
                    gameObject.GetComponent<MeshFilter>().mesh.triangles = sceneItem.triangles;
                    gameObject.GetComponent<MeshFilter>().mesh.RecalculateNormals();
                }
                if (sceneItem.BoxCollider == true)
                {
                    gameObject.AddComponent<BoxCollider>();
                }
                if (sceneItem.MeshRenderer == true)
                {
                    gameObject.AddComponent<MeshRenderer>();
                    gameObject.GetComponent<MeshRenderer>().material = AssetDatabase.GetBuiltinExtraResource<Material>("Default-Diffuse.mat");
                }

                gameObject.GetComponent<MeshRenderer>().material = AssetDatabase.GetBuiltinExtraResource<Material>("Default-Diffuse.mat");
            }
        }
    }
}