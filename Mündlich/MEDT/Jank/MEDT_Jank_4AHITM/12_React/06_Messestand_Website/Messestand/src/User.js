class User
{
    constructor(id = 0, name = '', role = UserRole.VISITOR)
    {
        this.id = id;
        this.name = name;
        this.role = role;
    }
}

// Enum for UserRole to match your backend roles
const UserRole = {
    ADMIN: 'Admin',
    EDITOR: 'Editor',
    VISITOR: 'Visitor'
};

export default User