using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;

public class Editor : MonoBehaviour {
    string path;
    string jsonString;

    void Start()
    {
        path = Application.streamingAssetsPath + "/json1.json";
        jsonString = File.ReadAllText(path);
        Map New = JsonUtility.FromJson<Map>(jsonString);
        Debug.Log(New.Name);
        New.Level = 25;
        string newNew = JsonUtility.ToJson(New);
        Debug.Log(newNew);
    }
}

public class Map
{
    public string Name;
    public int Level;
    public int[] Stats;
}
