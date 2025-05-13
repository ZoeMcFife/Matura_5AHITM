package meow;

import org.json.simple.JSONObject;

public class Product
{
    private String name;
    private String img;
    private Vendor vendor;

    Product(String name, String img, Vendor vendor)
    {
        setName(name);
        setImg(img);
        setVendor(vendor);
    }

    public static Product getProductJson(JSONObject json)
    {

        return new Product((String) json.get("name"), (String) json.get("img"), new Vendor((String) (((JSONObject)(json.get("vendor"))).get("firstname")), (String) (((JSONObject)(json.get("vendor"))).get("lastname"))));
    }

    @Override
    public String toString()
    {
        return getName() + " " + getImg() + " " + getVendor();
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setImg(String img)
    {
        this.img = img;
    }

    public void setVendor(Vendor vendor)
    {
        this.vendor = vendor;
    }

    public String getName()
    {
        return name;
    }

    public String getImg()
    {
        return img;
    }

    public Vendor getVendor()
    {
        return vendor;
    }
}
