package meow;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;

public class JSONTest
{
    public static void main(String[] args)
    {
        JSONParser jsonParser = new JSONParser();
        String home = System.getProperty("user.dir");
        String path = home + "/src/meow/products.json";
        System.out.println(path);

        File txtFile = new File(path);

        try
        {
            JSONObject jsonObject = (JSONObject) jsonParser.parse(new FileReader(txtFile));

            String name = (String) jsonObject.get("example");
            System.out.println(name);

            JSONArray list = (JSONArray) jsonObject.get("products");
            Iterator<JSONObject> iterator = list.iterator();

            while (iterator.hasNext())
            {
                Product product = Product.getProductJson(iterator.next());
                System.out.println(product);
            }

        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
        catch (ParseException e)
        {
            e.printStackTrace();
        }

    }
}
