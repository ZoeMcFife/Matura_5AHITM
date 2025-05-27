import './Button.css'

function Button(props)
{
    let visual = props.visualValue;
    let functional = props.functionalValue;

    function click ()
    {
        let result = document.getElementById("result");

        if (functional === '=')
        {
            result.value = eval(result.value);
            return;
        }

        if (functional === '%')
        {
            result.value += "*0.01";
            return;
        }


        if (functional === 'Clear')
        {
            result.value = "";
            return;
        }

        if (functional === 'Back')
        {
            result.value = result.value.slice(0, -1);
            return;
        }

        if (functional === 'pow')
        {
            result.value = surroundLastNumberWithPow(result.value);
            return;
        }

        if (functional === 'sqrt')
        {
            result.value = surroundLastNumberWithSqrt(result.value);
            return;
        }

        result.value += functional;

        console.log(result.value);
    }

    function surroundLastNumberWithPow(input)
    {
        return input.replace(/(\d+(\.\d+)?)(?!.*\d)/, (match) => `Math.pow(${match}, 2)`);
    }

    function surroundLastNumberWithSqrt(input)
    {
        return input.replace(/(\d+(\.\d+)?)(?!.*\d)/, (match) => `Math.sqrt(${match})`);
    }

    return (
        <button onClick={click}>{visual}</button>
    )
}

export default Button